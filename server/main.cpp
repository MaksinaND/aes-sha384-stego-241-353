#include <QCoreApplication>
#include <QDebug>
#include "apiserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    ApiServer server;
    
    if (!server.startServer(12345)) {
        qDebug() << "Не удалось запустить сервер";
        return -1;
    }

    qDebug() << "Сервер API запущен на порту 12345";
    qDebug() << "Нажмите Ctrl+C для остановки";

    return app.exec();
}

