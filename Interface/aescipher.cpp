#include "aescipher.h"
#include <QDebug>

AESCipher::AESCipher(QObject *parent) : QObject(parent), m_keySize(128), m_keySet(false)
{
}

bool AESCipher::setKey(const QByteArray &key, int keySize)
{
    // Проверяем размер ключа
    if (keySize != 128 && keySize != 192 && keySize != 256) {
        m_lastError = "Неверный размер ключа. Допустимые значения: 128, 192, 256 бит.";
        return false;
    }

    // Проверяем длину ключа в байтах
    int keySizeBytes = keySize / 8;
    if (key.size() < keySizeBytes) {
        m_lastError = QString("Ключ слишком короткий. Требуется %1 байт.").arg(keySizeBytes);
        return false;
    }

    // Используем только первые keySizeBytes байт ключа
    m_key = key.left(keySizeBytes);
    m_keySize = keySize;
    
    // Устанавливаем ключ в AES
    if (!m_aes.setKey(m_key)) {
        m_lastError = m_aes.lastError();
        return false;
    }
    
    m_keySet = true;
    return true;
}

QByteArray AESCipher::encrypt(const QByteArray &data)
{
    if (!m_keySet) {
        m_lastError = "Ключ не установлен.";
        return QByteArray();
    }

    // Дополняем данные до размера блока
    QByteArray paddedData = padData(data);
    
    // Шифруем данные
    QByteArray encryptedData;
    encryptedData.resize(paddedData.size());
    
    // Шифруем блоками по 16 байт (128 бит)
    for (int i = 0; i < paddedData.size(); i += 16) {
        m_aes.encrypt(reinterpret_cast<const uint8_t*>(paddedData.constData() + i), 
                     reinterpret_cast<uint8_t*>(encryptedData.data() + i));
    }
    
    return encryptedData;
}

QByteArray AESCipher::decrypt(const QByteArray &data)
{
    if (!m_keySet) {
        m_lastError = "Ключ не установлен.";
        return QByteArray();
    }

    // Проверяем, что размер данных кратен размеру блока
    if (data.size() % 16 != 0) {
        m_lastError = "Размер зашифрованных данных должен быть кратен 16 байтам.";
        return QByteArray();
    }
    
    // Дешифруем данные
    QByteArray decryptedData;
    decryptedData.resize(data.size());
    
    // Дешифруем блоками по 16 байт (128 бит)
    for (int i = 0; i < data.size(); i += 16) {
        m_aes.decrypt(reinterpret_cast<const uint8_t*>(data.constData() + i), 
                     reinterpret_cast<uint8_t*>(decryptedData.data() + i));
    }
    
    // Удаляем дополнение
    return unpadData(decryptedData);
}

QString AESCipher::encryptToBase64(const QString &text)
{
    QByteArray data = text.toUtf8();
    QByteArray encryptedData = encrypt(data);
    
    if (encryptedData.isEmpty()) {
        return QString();
    }
    
    return encryptedData.toBase64();
}

QString AESCipher::decryptFromBase64(const QString &base64)
{
    QByteArray encryptedData = QByteArray::fromBase64(base64.toLatin1());
    QByteArray decryptedData = decrypt(encryptedData);
    
    if (decryptedData.isEmpty()) {
        return QString();
    }
    
    return QString::fromUtf8(decryptedData);
}

QString AESCipher::encryptToHex(const QString &text)
{
    QByteArray data = text.toUtf8();
    QByteArray encryptedData = encrypt(data);
    
    if (encryptedData.isEmpty()) {
        return QString();
    }
    
    return encryptedData.toHex();
}

QString AESCipher::decryptFromHex(const QString &hex)
{
    QByteArray encryptedData = QByteArray::fromHex(hex.toLatin1());
    QByteArray decryptedData = decrypt(encryptedData);
    
    if (decryptedData.isEmpty()) {
        return QString();
    }
    
    return QString::fromUtf8(decryptedData);
}

QString AESCipher::lastError() const
{
    return m_lastError;
}

QByteArray AESCipher::padData(const QByteArray &data)
{
    // PKCS#7 padding
    int blockSize = 16; // 128 бит = 16 байт
    int paddingSize = blockSize - (data.size() % blockSize);
    
    QByteArray paddedData = data;
    for (int i = 0; i < paddingSize; i++) {
        paddedData.append(static_cast<char>(paddingSize));
    }
    
    return paddedData;
}

QByteArray AESCipher::unpadData(const QByteArray &data)
{
    // Проверяем, что данные не пустые
    if (data.isEmpty()) {
        return data;
    }
    
    // Получаем размер дополнения из последнего байта
    int paddingSize = static_cast<int>(data.at(data.size() - 1));
    
    // Проверяем корректность дополнения
    if (paddingSize <= 0 || paddingSize > 16) {
        m_lastError = "Некорректное дополнение.";
        return QByteArray();
    }
    
    // Проверяем, что все байты дополнения имеют одинаковое значение
    for (int i = data.size() - paddingSize; i < data.size(); i++) {
        if (static_cast<int>(data.at(i)) != paddingSize) {
            m_lastError = "Некорректное дополнение.";
            return QByteArray();
        }
    }
    
    // Удаляем дополнение
    return data.left(data.size() - paddingSize);
}

