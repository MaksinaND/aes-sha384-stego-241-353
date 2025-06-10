/**
 * @file mytcpserver.h
 * @brief TCP сервер для обработки клиентов EchoServer
 * @author Крючков Александр
 * @date 2025
 */
#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

/**
 * @class MyTcpServer
 * @brief Обработка TCP-подключений: регистрация, авторизация, работа с БД
 */
class MyTcpServer : public QObject {
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();

public slots:
    void slotNewConnection();                   ///< Новое подключение
    void slotClientDisconnected(QTcpSocket*);   ///< Отключение клиента
    void slotServerRead(QTcpSocket*);           ///< Чтение данных клиента

private:
    QTcpServer *mTcpServer;     ///< Сервер
    QList<QTcpSocket*> clients; ///< Список клиентов
};

#endif // MYTCPSERVER_H
