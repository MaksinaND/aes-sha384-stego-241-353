/**
 * @file databasemanager.cpp
 * @brief Реализация DatabaseManager (SQLite)
 * @author Крючков Александр
 * @date 2025
 */
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager* DatabaseManager::instance = nullptr;

/**
 * @brief Инициализирует БД: подключение, создание таблиц messages/users
 */
DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("project_data.db");

    if (!db.open()) {
        qDebug() << "Ошибка открытия БД:" << db.lastError().text();
    } else {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS messages (...)");
        query.exec("CREATE TABLE IF NOT EXISTS users (...)");
    }
}

DatabaseManager* DatabaseManager::getInstance() {
    if (!instance) instance = new DatabaseManager();
    return instance;
}

QSqlDatabase DatabaseManager::getDatabase() {
    return db;
}
