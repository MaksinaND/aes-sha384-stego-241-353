#include "myclient.h"
#include <QDebug>

MyClient* MyClient::instance = nullptr;

MyClient* MyClient::getInstance() {
    if (!instance)
        instance = new MyClient();
    return instance;
}

MyClient::MyClient(QObject* parent) : QObject(parent) {
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &MyClient::onConnected);
    connect(socket, &QTcpSocket::readyRead, this, &MyClient::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &MyClient::onDisconnected);
}

void MyClient::connectToServer() {
    socket->connectToHost("127.0.0.1", 33333);
}

void MyClient::sendCommand(const QString& command) {
    qDebug() << "2" << MyClient::getInstance();
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(command.toUtf8() + "\r\n");
    } else {
        qDebug() << "⚠️ Сокет не подключен";
    }
}

void MyClient::onConnected() {
    qDebug() << "✅ Подключено к серверу";
    qDebug() << "3" << MyClient::getInstance();
    sendCommand("reg test:123");
}

void MyClient::onReadyRead() {
    QByteArray response = socket->readAll();
    qDebug() << "📩 Ответ сервера:" << response;
}

void MyClient::onDisconnected() {
    qDebug() << "❌ Отключено от сервера";
}
