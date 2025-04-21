#pragma once
#include <QTcpSocket>
#include <QObject>

class MyClient : public QObject {
    Q_OBJECT
public:
    static MyClient* getInstance();              // ← добавлено
    void connectToServer();
    void sendCommand(const QString& command);

private slots:
    void onConnected();
    void onReadyRead();
    void onDisconnected();

private:
    explicit MyClient(QObject* parent = nullptr);
    QTcpSocket* socket;

    static MyClient* instance;                   // ← добавлено
};
