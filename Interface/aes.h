#ifndef AES_H
#define AES_H

#include <QObject>
#include <QString>
#include <QByteArray>
#include <QVector>

/**
 * @brief Класс AES реализует алгоритм шифрования Advanced Encryption Standard
 * 
 * Эта реализация поддерживает ключи длиной 128, 192 и 256 бит.
 * Режим работы - ECB (Electronic Codebook).
 */
class AES : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса AES
     * @param parent Родительский объект
     */
    explicit AES(QObject *parent = nullptr);

    /**
     * @brief Устанавливает ключ шифрования
     * @param key Ключ шифрования (должен быть 16, 24 или 32 байта)
     * @param keySize Размер ключа в битах (128, 192 или 256)
     * @return true, если ключ установлен успешно, иначе false
     */
    bool setKey(const QByteArray &key);
    
    /**
     * @brief Устанавливает ключ шифрования
     * @param key Указатель на ключ шифрования
     * @param keySize Размер ключа в битах (128, 192 или 256)
     * @return true, если ключ установлен успешно, иначе false
     */
    bool setKey(const char* key, int keySize);

    /**
     * @brief Шифрует данные
     * @param plaintext Открытый текст
     * @return Зашифрованный текст
     */
    QByteArray encrypt(const QByteArray &plaintext);
    
    /**
     * @brief Шифрует блок данных
     * @param input Указатель на входные данные (размер блока 16 байт)
     * @param output Указатель на выходные данные (размер блока 16 байт)
     */
    void encrypt(const uint8_t* input, uint8_t* output);

    /**
     * @brief Дешифрует данные
     * @param ciphertext Зашифрованный текст
     * @return Открытый текст
     */
    QByteArray decrypt(const QByteArray &ciphertext);
    
    /**
     * @brief Дешифрует блок данных
     * @param input Указатель на входные данные (размер блока 16 байт)
     * @param output Указатель на выходные данные (размер блока 16 байт)
     */
    void decrypt(const uint8_t* input, uint8_t* output);

    /**
     * @brief Возвращает последнюю ошибку
     * @return Текст ошибки
     */
    QString lastError() const;

private:
    // Константы
    static const int BLOCK_SIZE = 16; // 128 бит
    static const int Nb = 4;  // Количество столбцов (32-битных слов) в состоянии
    static const int Nr_128 = 10; // Количество раундов для 128-битного ключа
    static const int Nr_192 = 12; // Количество раундов для 192-битного ключа
    static const int Nr_256 = 14; // Количество раундов для 256-битного ключа

    // Таблицы для операций
    static const quint8 sbox[256];
    static const quint8 inv_sbox[256];
    static const quint8 rcon[11];

    // Состояние и ключи
    QVector<QVector<quint8>> state;
    QVector<QVector<quint8>> roundKeys;
    int Nr; // Текущее количество раундов (зависит от длины ключа)
    int Nk; // Количество 32-битных слов в ключе

    QString m_lastError;

    // Вспомогательные функции
    void keyExpansion(const QByteArray &key);
    void addRoundKey(int round);
    void subBytes();
    void invSubBytes();
    void shiftRows();
    void invShiftRows();
    void mixColumns();
    void invMixColumns();
    
    // Вспомогательные математические функции
    quint8 gmul(quint8 a, quint8 b); // Умножение в поле Галуа GF(2^8)
    
    // Функции для работы с состоянием
    void bytesToState(const QByteArray &bytes);
    void bytesToState(const uint8_t* bytes);
    QByteArray stateToBytes();
    void stateToBytes(uint8_t* bytes);
    
    // Функции для работы с блоками
    QByteArray padData(const QByteArray &data);
    QByteArray unpadData(const QByteArray &data);
};

#endif // AES_H

