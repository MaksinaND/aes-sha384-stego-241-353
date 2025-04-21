#pragma once
#include <QTcpSocket>
#include <QObject>

class MyClient : public QObject {
    Q_OBJECT
public:
    explicit MyClient(QObject* parent = nullptr);
    void connectToServer();
    void sendCommand(const QString& command);

private slots:
    void onConnected();
    void onReadyRead();
    void onDisconnected();

private:
    QTcpSocket* socket;
};
