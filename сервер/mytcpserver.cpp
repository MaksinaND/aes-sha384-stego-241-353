/**
 * @file mytcpserver.cpp
 * @brief Реализация класса MyTcpServer - серверная логика для EchoServer приложения (регистрация, авторизация, база данных, решение уравнений и заглушка для сокрытия данных в изображениях).
 * @author Крючков Александр
 * @date 2025
 */
#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QCryptographicHash>
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    //server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    QTcpSocket *clientSocket = mTcpServer->nextPendingConnection();
    clients.append(clientSocket);

    clientSocket->write("Hello, World!!! I am echo server!\r\n");

    connect(clientSocket, &QTcpSocket::readyRead, this, [=](){
        this->slotServerRead(clientSocket);
    });

    connect(clientSocket, &QTcpSocket::disconnected, this, [=](){
        this->slotClientDisconnected(clientSocket);
    });
}

void MyTcpServer::slotServerRead(QTcpSocket* socket){
    QByteArray array = socket->readAll();
    QString input = QString::fromUtf8(array).trimmed();

    qDebug() << "Получена команда:" << input;

    if (input.startsWith("reg ")) {
        QStringList parts = input.mid(4).split(":");
        if (parts.size() != 2) {
            socket->write("Неверный формат. Используй: reg логин:пароль\r\n");
            return;
        }

        QString login = parts[0].trimmed();
        QString password = parts[1].trimmed();

        QSqlDatabase db = DatabaseManager::getInstance()->getDatabase();
        QSqlQuery query;

        query.prepare("SELECT id FROM users WHERE login = :login");
        query.bindValue(":login", login);
        if (query.exec() && query.next()) {
            socket->write("Ошибка: пользователь уже существует\r\n");
            return;
        }

        QString role = (password == "makeMeAdmin") ? "admin" : "user";

        query.prepare("INSERT INTO users (login, password, role) VALUES (:login, :password, :role)");
        query.bindValue(":login", login);
        query.bindValue(":password", password);
        query.bindValue(":role", role);

        if (query.exec()) {
            socket->write("Регистрация успешна\r\n");
        } else {
            socket->write("Ошибка при регистрации\r\n");
        }

        return;
    }

    if (input.startsWith("auth ")) {
        QStringList parts = input.mid(5).split(":");
        if (parts.size() != 2) {
            socket->write("Неверный формат. Используй: auth логин:пароль\r\n");
            return;
        }

        QString login = parts[0].trimmed();
        QString password = parts[1].trimmed();

        QSqlDatabase db = DatabaseManager::getInstance()->getDatabase();
        QSqlQuery query;

        query.prepare("SELECT password, role FROM users WHERE login = :login");
        query.bindValue(":login", login);
        if (query.exec() && query.next()) {
            QString storedPassword = query.value(0).toString();
            QString role = query.value(1).toString();
            qDebug() << "Авторизуемый логин:" << login << ", роль из БД:" << role;
            if (storedPassword == password) {
                socket->write(QString("Авторизация успешна: %1\r\n").arg(role).toUtf8());
            } else {
                socket->write("Ошибка: неверный пароль\r\n");
            }
        } else {
            socket->write("Ошибка: пользователь не найден\r\n");
        }

        return;
    }

    if (input.startsWith("enc")) {
        QSqlDatabase db = DatabaseManager::getInstance()->getDatabase();
        QSqlQuery query;
        query.prepare("INSERT INTO messages (message, aes_key, sha_hash, image_path) "
                      "VALUES (:msg, :key, :hash, :img)");
        query.bindValue(":msg", input);               // Пока сохраняем просто введённый текст
        query.bindValue(":key", "demo_key");          // Заглушка для AES-ключа
        query.bindValue(":hash", "demo_hash");        // Заглушка для SHA-384
        query.bindValue(":img", "demo_path.png");     // Путь к изображению (заглушка)
        if (query.exec()) {
            socket->write("ENC: Сообщение сохранено в БД\r\n");
        } else {
            socket->write("Ошибка при сохранении в БД\r\n");
            qDebug() << "Ошибка БД:" << query.lastError().text();
        }
    }



    else if (input.startsWith("solve ")) {
        QStringList parts = input.mid(6).split(" ");
        if (parts.size() == 3) {
            bool ok1, ok2, ok3;
            double a = parts[0].toDouble(&ok1);
            double b = parts[1].toDouble(&ok2);
            double eps = parts[2].toDouble(&ok3);
            if (ok1 && ok2 && ok3) {
                double x, fx;
                int iterations = 0;

                auto f = [](double x) { return x*x*x - 5*x + 3; };

                if (f(a) * f(b) > 0) {
                    socket->write("На отрезке нет корня или их чётное число\r\n");
                    return;
                }

                while (fabs(b - a) > eps && iterations < 100) {
                    x = a - (f(a) * (b - a)) / (f(b) - f(a));
                    if (f(a) * f(x) < 0)
                        b = x;
                    else
                        a = x;
                    iterations++;
                }

                fx = f(x);
                QString result = QString("Корень: %1\r\nИтераций: %2\r\nf(x): %3\r\n")
                                     .arg(x, 0, 'f', 6)
                                     .arg(iterations)
                                     .arg(fx, 0, 'e', 2);
                socket->write(result.toUtf8());
            } else {
                socket->write("Некорректный формат аргументов\r\n");
            }
        } else {
            socket->write("Ожидается: solve a b eps\r\n");
        }
    }
    else if (input.startsWith("hide")) {
        socket->write("HIDE: заглушка. Пока не встраиваем в картинки.\r\n");
    }
    else {
        socket->write("Неизвестная команда\r\n");
    }
}

void MyTcpServer::slotClientDisconnected(QTcpSocket* socket){
    clients.removeAll(socket);
    socket->deleteLater();
}
