#ifndef APICLIENT_H
#define APICLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QString>
#include <QImage>
#include <QBuffer>
#include <QDebug>

/**
 * @brief Класс ApiClient для отправки API-запросов на сервер
 * 
 * Класс реализует паттерн Singleton и предоставляет методы для вызова
 * функций AES, Steganography и SHA384 через API
 */
class ApiClient : public QObject
{
    Q_OBJECT

signals:
    /**
     * @brief Сигнал получения ответа от сервера
     * @param endpoint Конечная точка API
     * @param success Успешность операции
     * @param result Результат операции
     * @param error Описание ошибки (если есть)
     */
    void responseReceived(const QString &endpoint, bool success, const QJsonObject &result, const QString &error);

public:
    /**
     * @brief Получить экземпляр ApiClient (Singleton)
     * @return Указатель на экземпляр ApiClient
     */
    static ApiClient* getInstance();

    /**
     * @brief Подключиться к серверу
     * @param host Адрес сервера
     * @param port Порт сервера
     */
    void connectToServer(const QString &host = "localhost", quint16 port = 12345);

    /**
     * @brief Отключиться от сервера
     */
    void disconnectFromServer();

    /**
     * @brief Проверить состояние подключения
     * @return true, если подключен к серверу
     */
    bool isConnected() const;

    // User API methods
    void registerUser(const QString& username, const QString& password);
    void loginUser(const QString& username, const QString& password);

    // Message API methods
    void sendMessage(const QString& sender, const QString& receiver, const QString& message);
    void getMessages(const QString& username);

    // AES API методы
    /**
     * @brief Зашифровать данные с помощью AES
     * @param key Ключ шифрования
     * @param plaintext Открытый текст
     */
    void aesEncrypt(const QByteArray &key, const QByteArray &plaintext);

    /**
     * @brief Расшифровать данные с помощью AES
     * @param key Ключ шифрования
     * @param ciphertext Зашифрованный текст
     */
    void aesDecrypt(const QByteArray &key, const QString &ciphertext);

    /**
     * @brief Внедрить сообщение в изображение
     * @param image Исходное изображение
     * @param message Сообщение для внедрения
     */
    void stegoEmbed(const QImage &image, const QString &message);

    /**
     * @brief Извлечь сообщение из изображения
     * @param image Изображение с внедренным сообщением
     */
    void stegoExtract(const QImage &image);

    /**
     * @brief Проверить наличие сообщения в изображении
     * @param image Изображение для проверки
     */
    void stegoHasMessage(const QImage &image);

    // SHA384 API методы
    /**
     * @brief Вычислить хеш SHA384
     * @param data Данные для хеширования
     */
    void sha384Hash(const QByteArray &data);

    /**
     * @brief Отправить JSON-запрос на сервер
     * @param endpoint Конечная точка API
     * @param data Данные запроса
     */
    void sendRequest(const QString &endpoint, const QJsonObject &data);

    /**
     * @brief Конвертировать QByteArray в Base64 строку
     * @param data Данные для конвертации
     * @return Base64 строка
     */
    QString toBase64(const QByteArray &data);

    /**
     * @brief Конвертировать Base64 строку в QByteArray
     * @param base64 Base64 строка
     * @return QByteArray данные
     */
    QByteArray fromBase64(const QString &base64);

    /**
     * @brief Конвертировать QImage в Base64 строку
     * @param image Изображение для конвертации
     * @return Base64 строка
     */
    QString imageToBase64(const QImage &image);

    /**
     * @brief Конвертировать Base64 строку в QImage
     * @param base64 Base64 строка
     * @return QImage изображение
     */
    QImage imageFromBase64(const QString &base64);

private slots:
    void onConnected();
    void onReadyRead();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError error);

private:
    explicit ApiClient(QObject *parent = nullptr);

    QTcpSocket *socket;
    QByteArray buffer; // Добавляем буфер для чтения фрагментированных сообщений
    QString m_lastSentEndpoint; // Добавляем переменную для хранения последнего отправленного endpoint
    static ApiClient *instance;
};

#endif // APICLIENT_H


