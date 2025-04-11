#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include<QString>

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
    //   if(server_status==1){
    mTcpSocket = mTcpServer->nextPendingConnection();
    mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
    connect(mTcpSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
    connect(mTcpSocket,&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
    // }
}

void MyTcpServer::slotServerRead(){
    QByteArray array = mTcpSocket->readAll();
    QString input = QString::fromUtf8(array).trimmed();

    qDebug() << "Получена команда:" << input;

    if (input.isEmpty()) {
        mTcpSocket->write("Пустая команда. Повтори.\r\n");
        return;
    }

    if (input.startsWith("enc")) {
        mTcpSocket->write("ENC: заглушка. Шифрование пока не реализовано.\r\n");
    }
    else if (input.startsWith("hash")) {
        mTcpSocket->write("HASH: заглушка. Хэш пока не реализован.\r\n");
    }
    else if (input.startsWith("solve")) {
        mTcpSocket->write("SOLVE: заглушка. Решатель ещё не готов.\r\n");
    }
    else if (input.startsWith("hide")) {
        mTcpSocket->write("HIDE: заглушка. Пока не встраиваем в картинки.\r\n");
    }
    else {
        mTcpSocket->write("Неизвестная команда\r\n");
    }
}



void MyTcpServer::slotClientDisconnected(){
    mTcpSocket->close();
}
