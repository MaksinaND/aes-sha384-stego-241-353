#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVector>
#include <QPair>

class DatabaseManager {
public:
    static DatabaseManager* getInstance();
    QSqlDatabase getDatabase();

    bool registerUser(const QString& username, const QString& password);
    bool loginUser(const QString& username, const QString& password);
    bool sendMessage(const QString& sender, const QString& receiver, const QString& message);
    QVector<QPair<QString, QString>> getMessages(const QString& username);

private:
    static DatabaseManager* instance;
    QSqlDatabase db;

    DatabaseManager();  // Приватный конструктор
};

#endif // DATABASEMANAGER_H


