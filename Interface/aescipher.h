#ifndef AESCIPHER_H
#define AESCIPHER_H

#include <QObject>
#include <QString>
#include <QByteArray>
#include "aes.h"

/**
 * @brief Класс AESCipher предоставляет удобный интерфейс для работы с AES шифрованием
 */
class AESCipher : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса AESCipher
     * @param parent Родительский объект
     */
    explicit AESCipher(QObject *parent = nullptr);

    /**
     * @brief Устанавливает ключ шифрования
     * @param key Ключ шифрования
     * @param keySize Размер ключа (128, 192 или 256 бит)
     * @return true, если ключ установлен успешно, иначе false
     */
    bool setKey(const QByteArray &key, int keySize);

    /**
     * @brief Шифрует данные
     * @param data Данные для шифрования
     * @return Зашифрованные данные
     */
    QByteArray encrypt(const QByteArray &data);

    /**
     * @brief Дешифрует данные
     * @param data Данные для дешифрования
     * @return Дешифрованные данные
     */
    QByteArray decrypt(const QByteArray &data);

    /**
     * @brief Шифрует текст и возвращает результат в виде Base64
     * @param text Текст для шифрования
     * @return Зашифрованный текст в формате Base64
     */
    QString encryptToBase64(const QString &text);

    /**
     * @brief Дешифрует текст из формата Base64
     * @param base64 Текст в формате Base64 для дешифрования
     * @return Дешифрованный текст
     */
    QString decryptFromBase64(const QString &base64);

    /**
     * @brief Шифрует текст и возвращает результат в виде шестнадцатеричной строки
     * @param text Текст для шифрования
     * @return Зашифрованный текст в шестнадцатеричном формате
     */
    QString encryptToHex(const QString &text);

    /**
     * @brief Дешифрует текст из шестнадцатеричного формата
     * @param hex Текст в шестнадцатеричном формате для дешифрования
     * @return Дешифрованный текст
     */
    QString decryptFromHex(const QString &hex);

    /**
     * @brief Возвращает последнюю ошибку
     * @return Текст ошибки
     */
    QString lastError() const;

private:
    AES m_aes;
    QString m_lastError;
    QByteArray m_key;
    int m_keySize;
    bool m_keySet;

    /**
     * @brief Дополняет данные до размера блока
     * @param data Данные для дополнения
     * @return Дополненные данные
     */
    QByteArray padData(const QByteArray &data);

    /**
     * @brief Удаляет дополнение из данных
     * @param data Данные с дополнением
     * @return Данные без дополнения
     */
    QByteArray unpadData(const QByteArray &data);
};

#endif // AESCIPHER_H

