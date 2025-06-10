/**
 * @file databasemanager.h
 * @brief Управление SQLite БД (Singleton)
 * @author Крючков Александр
 * @date 2025
 */
#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

/**
 * @class DatabaseManager
 * @brief Singleton для работы с SQLite: подключение, создание таблиц
 */
class DatabaseManager {
public:
    static DatabaseManager* getInstance(); ///< Возвращает единственный экземпляр
    QSqlDatabase getDatabase();           ///< Возвращает объект БД

private:
    static DatabaseManager* instance; ///< Единственный экземпляр
    QSqlDatabase db;                 ///< Объект базы данных
    DatabaseManager();               ///< Приватный конструктор
};

#endif // DATABASEMANAGER_H
