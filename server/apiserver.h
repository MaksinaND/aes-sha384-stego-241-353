#ifndef APISERVER_H
#define APISERVER_H

#include <QJsonArray>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QByteArray>
#include <QString>
#include <QDebug>

#include "aes.h"
#include "steganography.h"
#include "sha384.h"
#include "chordmethod.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "databasemanager.h"

/**
 * @brief Класс ApiServer реализует TCP сервер с JSON API
 * 
 * Сервер обрабатывает запросы для функций AES, Steganography и SHA384
 */
class ApiServer : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса ApiServer
     * @param parent Родительский объект
     */
    explicit ApiServer(QObject *parent = nullptr);

    /**
     * @brief Запускает сервер на указанном порту
     * @param port Порт для прослушивания
     * @return true, если сервер запущен успешно, иначе false
     */
    bool startServer(quint16 port = 12345);

    /**
     * @brief Останавливает сервер
     */
    void stopServer();

private slots:
    /**
     * @brief Обрабатывает новое подключение клиента
     */
    void onNewConnection();

    /**
     * @brief Обрабатывает данные от клиента
     */
    void onReadyRead();

    /**
     * @brief Обрабатывает отключение клиента
     */
    void onClientDisconnected();

private:
    QTcpServer *tcpServer;
    AES *aes;
    Steganography *steganography;
    SHA384 *sha384;
    ChordMethod *chordMethod;
    QByteArray buffer;
    DatabaseManager* dbManager;

    /**
     * @brief Обрабатывает JSON запрос и возвращает JSON ответ
     * @param request JSON запрос
     * @return JSON ответ
     */
    QJsonObject processRequest(const QJsonObject &request);

    /**
     * @brief Обрабатывает AES запросы
     * @param endpoint Конечная точка (/aes/encrypt или /aes/decrypt)
     * @param data Данные запроса
     * @return JSON ответ
     */
    QJsonObject handleAesRequest(const QString &endpoint, const QJsonObject &data);

    /**
     * @brief Обрабатывает Steganography запросы
     * @param endpoint Конечная точка (/stego/embed, /stego/extract, /stego/has_message)
     * @param data Данные запроса
     * @return JSON ответ
     */
    QJsonObject handleStegoRequest(const QString &endpoint, const QJsonObject &data);

    /**
     * @brief Обрабатывает SHA384 запросы
     * @param endpoint Конечная точка (/sha384/hash)
     * @param data Данные запроса
     * @return JSON ответ
     */
    QJsonObject handleSha384Request(const QString &endpoint, const QJsonObject &data);

    /**
     * @brief Обрабатывает запросы метода хорд
     * @param endpoint Конечная точка (/chord_method/solve)
     * @param data Данные запроса
     * @return JSON ответ
     */
    QJsonObject handleChordMethodRequest(const QString &endpoint, const QJsonObject &data);

    QJsonObject handleUserRequest(const QString &endpoint, const QJsonObject &data);
    QJsonObject handleMessageRequest(const QString &endpoint, const QJsonObject &data);

    /**
     * @brief Создает JSON ответ об успехе
     * @param result Результат операции
     * @return JSON ответ
     */
    QJsonObject createSuccessResponse(const QJsonObject &result);

    /**
     * @brief Создает JSON ответ об ошибке
     * @param error Описание ошибки
     * @return JSON ответ
     */
    QJsonObject createErrorResponse(const QString &error);

    /**
     * @brief Конвертирует QByteArray в Base64 строку
     * @param data Данные для конвертации
     * @return Base64 строка
     */
    QString toBase64(const QByteArray &data);

    /**
     * @brief Конвертирует Base64 строку в QByteArray
     * @param base64 Base64 строка
     * @return QByteArray данные
     */
    QByteArray fromBase64(const QString &base64);

    /**
     * @brief Конвертирует QImage в Base64 строку
     * @param image Изображение для конвертации
     * @return Base64 строка
     */
    QString imageToBase64(const QImage &image);

    /**
     * @brief Конвертирует Base64 строку в QImage
     * @param base64 Base64 строка
     * @return QImage изображение
     */
    QImage imageFromBase64(const QString &base64);
};

#endif // APISERVER_H

