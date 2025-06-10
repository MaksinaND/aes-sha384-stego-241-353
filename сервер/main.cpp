/**
 * @file main.cpp
 * @brief Точка входа EchoServer
 * @details Запускает TCP сервер и Qt Event Loop.
 * @date 2025
 */
#include <QCoreApplication>
#include "mytcpserver.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    MyTcpServer myserv; // Сервер стартует автоматически в конструкторе
    return a.exec();
}
