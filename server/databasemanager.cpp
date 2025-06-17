#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager* DatabaseManager::instance = nullptr;

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("project_data.db");

    if (!db.open()) {
        qDebug() << "Не удалось открыть БД:" << db.lastError().text();
    } else {
        qDebug() << "База данных успешно открыта.";

        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS messages ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "message TEXT)");
        query.exec("CREATE TABLE IF NOT EXISTS users ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "login TEXT UNIQUE, "
                   "password TEXT)");

    }
}

DatabaseManager* DatabaseManager::getInstance() {
    if (!instance)
        instance = new DatabaseManager();
    return instance;
}

QSqlDatabase DatabaseManager::getDatabase() {
    return db;
}


bool DatabaseManager::registerUser(const QString& username, const QString& password) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO users (login, password) VALUES (:login, :password)");
    query.bindValue(":login", username);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qDebug() << "Ошибка регистрации пользователя:" << query.lastError().text();
        qDebug() << "SQL Query:" << query.lastQuery();
        qDebug() << "Bound Values:" << query.boundValues();
        return false;
    }
    return true;
}

bool DatabaseManager::loginUser(const QString& username, const QString& password) {
    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE login = :login AND password = :password");
    query.bindValue(":login", username);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qDebug() << "Ошибка входа пользователя:" << query.lastError().text();
        return false;
    }
    return query.next(); // Если есть следующая запись, значит пользователь найден
}

bool DatabaseManager::sendMessage(const QString& sender, const QString& receiver, const QString& message) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO messages (sender, receiver, message) VALUES (:sender, :receiver, :message)");
    query.bindValue(":sender", sender);
    query.bindValue(":receiver", receiver);
    query.bindValue(":message", message);
    if (!query.exec()) {
        qDebug() << "Ошибка отправки сообщения:" << query.lastError().text();
        return false;
    }
    return true;
}

QVector<QPair<QString, QString>> DatabaseManager::getMessages(const QString& username) {
    QVector<QPair<QString, QString>> messages;
    QSqlQuery query(db);
    query.prepare("SELECT sender, message FROM messages WHERE receiver = :receiver");
    query.bindValue(":receiver", username);
    if (!query.exec()) {
        qDebug() << "Ошибка получения сообщений:" << query.lastError().text();
        return messages;
    }
    while (query.next()) {
        messages.append(qMakePair(query.value(0).toString(), query.value(1).toString()));
    }
    return messages;
}


