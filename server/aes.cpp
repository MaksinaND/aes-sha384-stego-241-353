#include "aes.h"

// S-box таблица для SubBytes
const quint8 AES::sbox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};

// Обратная S-box таблица для InvSubBytes
const quint8 AES::inv_sbox[256] = {
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};

// Таблица констант раунда для расширения ключа
const quint8 AES::rcon[11] = {
    0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36
};

AES::AES(QObject *parent) : QObject(parent), Nr(0), Nk(0)
{
    // Инициализация состояния
    state.resize(4);
    for (int i = 0; i < 4; i++) {
        state[i].resize(Nb);
    }
}

bool AES::setKey(const QByteArray &key)
{
    // Проверяем длину ключа
    if (key.size() == 16) { // 128 бит
        Nk = 4;
        Nr = Nr_128;
    } else if (key.size() == 24) { // 192 бит
        Nk = 6;
        Nr = Nr_192;
    } else if (key.size() == 32) { // 256 бит
        Nk = 8;
        Nr = Nr_256;
    } else {
        m_lastError = "Неверная длина ключа. Должна быть 16, 24 или 32 байта.";
        return false;
    }

    // Расширяем ключ
    keyExpansion(key);
    return true;
}

bool AES::setKey(const char* key, int keySize)
{
    // Преобразуем размер ключа из бит в байты
    int keySizeBytes = keySize / 8;
    
    // Создаем QByteArray из указателя на ключ
    QByteArray keyArray = QByteArray(key, keySizeBytes);
    
    // Используем существующий метод для установки ключа
    return setKey(keyArray);
}

QByteArray AES::encrypt(const QByteArray &plaintext)
{
    // Проверяем, установлен ли ключ
    if (Nr == 0) {
        m_lastError = "Ключ не установлен.";
        return QByteArray();
    }

    // Дополняем данные до размера, кратного размеру блока
    QByteArray paddedData = padData(plaintext);
    QByteArray result;

    // Шифруем каждый блок
    for (int i = 0; i < paddedData.size(); i += BLOCK_SIZE) {
        QByteArray block = paddedData.mid(i, BLOCK_SIZE);
        
        // Преобразуем блок в состояние
        bytesToState(block);
        
        // Начальное добавление ключа раунда
        addRoundKey(0);
        
        // Основные раунды
        for (int round = 1; round < Nr; round++) {
            subBytes();
            shiftRows();
            mixColumns();
            addRoundKey(round);
        }
        
        // Последний раунд (без mixColumns)
        subBytes();
        shiftRows();
        addRoundKey(Nr);
        
        // Добавляем зашифрованный блок к результату
        result.append(stateToBytes());
    }

    return result;
}

void AES::encrypt(const uint8_t* input, uint8_t* output)
{
    // Проверяем, установлен ли ключ
    if (Nr == 0) {
        m_lastError = "Ключ не установлен.";
        return;
    }
    
    // Преобразуем входные данные в состояние
    bytesToState(input);
    
    // Начальное добавление ключа раунда
    addRoundKey(0);
    
    // Основные раунды
    for (int round = 1; round < Nr; round++) {
        subBytes();
        shiftRows();
        mixColumns();
        addRoundKey(round);
    }
    
    // Последний раунд (без mixColumns)
    subBytes();
    shiftRows();
    addRoundKey(Nr);
    
    // Преобразуем состояние в выходные данные
    stateToBytes(output);
}

QByteArray AES::decrypt(const QByteArray &ciphertext)
{
    // Проверяем, установлен ли ключ
    if (Nr == 0) {
        m_lastError = "Ключ не установлен.";
        return QByteArray();
    }

    // Проверяем, что размер данных кратен размеру блока
    if (ciphertext.size() % BLOCK_SIZE != 0) {
        m_lastError = "Размер зашифрованных данных должен быть кратен размеру блока.";
        return QByteArray();
    }

    QByteArray result;

    // Дешифруем каждый блок
    for (int i = 0; i < ciphertext.size(); i += BLOCK_SIZE) {
        QByteArray block = ciphertext.mid(i, BLOCK_SIZE);
        
        // Преобразуем блок в состояние
        bytesToState(block);
        
        // Начальное добавление ключа раунда
        addRoundKey(Nr);
        
        // Основные раунды
        for (int round = Nr - 1; round > 0; round--) {
            invShiftRows();
            invSubBytes();
            addRoundKey(round);
            invMixColumns();
        }
        
        // Последний раунд (без invMixColumns)
        invShiftRows();
        invSubBytes();
        addRoundKey(0);
        
        // Добавляем дешифрованный блок к результату
        result.append(stateToBytes());
    }

    // Удаляем дополнение
    return unpadData(result);
}

void AES::decrypt(const uint8_t* input, uint8_t* output)
{
    // Проверяем, установлен ли ключ
    if (Nr == 0) {
        m_lastError = "Ключ не установлен.";
        return;
    }
    
    // Преобразуем входные данные в состояние
    bytesToState(input);
    
    // Начальное добавление ключа раунда
    addRoundKey(Nr);
    
    // Основные раунды
    for (int round = Nr - 1; round > 0; round--) {
        invShiftRows();
        invSubBytes();
        invMixColumns();
        addRoundKey(round);
    }
    
    // Последний раунд (без invMixColumns)
    invShiftRows();
    invSubBytes();
    addRoundKey(0);
    
    // Преобразуем состояние в выходные данные
    stateToBytes(output);
}

QString AES::lastError() const
{
    return m_lastError;
}

void AES::keyExpansion(const QByteArray &key)
{
    // Количество 32-битных слов в расширенном ключе
    int Nw = Nb * (Nr + 1);
    
    // Инициализация расширенного ключа
    roundKeys.resize(Nw);
    for (int i = 0; i < Nw; i++) {
        roundKeys[i].resize(4);
    }
    
    // Копируем исходный ключ в начало расширенного ключа
    for (int i = 0; i < Nk; i++) {
        for (int j = 0; j < 4; j++) {
            roundKeys[i][j] = static_cast<quint8>(key[i * 4 + j]);
        }
    }
    
    // Расширяем ключ
    for (int i = Nk; i < Nw; i++) {
        QVector<quint8> temp = roundKeys[i - 1];
        
        if (i % Nk == 0) {
            // RotWord: циклический сдвиг влево
            quint8 temp0 = temp[0];
            temp[0] = temp[1];
            temp[1] = temp[2];
            temp[2] = temp[3];
            temp[3] = temp0;
            
            // SubWord: замена байтов через S-box
            for (int j = 0; j < 4; j++) {
                temp[j] = sbox[temp[j]];
            }
            
            // XOR с Rcon
            temp[0] ^= rcon[i / Nk];
        } else if (Nk > 6 && i % Nk == 4) {
            // Дополнительная замена для 256-битного ключа
            for (int j = 0; j < 4; j++) {
                temp[j] = sbox[temp[j]];
            }
        }
        
        // XOR с предыдущим словом ключа
        for (int j = 0; j < 4; j++) {
            roundKeys[i][j] = roundKeys[i - Nk][j] ^ temp[j];
        }
    }
}

void AES::addRoundKey(int round)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < Nb; j++) {
            state[i][j] ^= roundKeys[round * Nb + j][i];
        }
    }
}

void AES::subBytes()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < Nb; j++) {
            state[i][j] = sbox[state[i][j]];
        }
    }
}

void AES::invSubBytes()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < Nb; j++) {
            state[i][j] = inv_sbox[state[i][j]];
        }
    }
}

void AES::shiftRows()
{
    // Первая строка не сдвигается
    
    // Вторая строка - сдвиг на 1 позицию влево
    quint8 temp = state[1][0];
    state[1][0] = state[1][1];
    state[1][1] = state[1][2];
    state[1][2] = state[1][3];
    state[1][3] = temp;
    
    // Третья строка - сдвиг на 2 позиции влево
    temp = state[2][0];
    state[2][0] = state[2][2];
    state[2][2] = temp;
    temp = state[2][1];
    state[2][1] = state[2][3];
    state[2][3] = temp;
    
    // Четвертая строка - сдвиг на 3 позиции влево (или на 1 вправо)
    temp = state[3][3];
    state[3][3] = state[3][2];
    state[3][2] = state[3][1];
    state[3][1] = state[3][0];
    state[3][0] = temp;
}

void AES::invShiftRows()
{
    // Первая строка не сдвигается
    
    // Вторая строка - сдвиг на 1 позицию вправо
    quint8 temp = state[1][3];
    state[1][3] = state[1][2];
    state[1][2] = state[1][1];
    state[1][1] = state[1][0];
    state[1][0] = temp;
    
    // Третья строка - сдвиг на 2 позиции вправо
    temp = state[2][0];
    state[2][0] = state[2][2];
    state[2][2] = temp;
    temp = state[2][1];
    state[2][1] = state[2][3];
    state[2][3] = temp;
    
    // Четвертая строка - сдвиг на 3 позиции вправо (или на 1 влево)
    temp = state[3][0];
    state[3][0] = state[3][1];
    state[3][1] = state[3][2];
    state[3][2] = state[3][3];
    state[3][3] = temp;
}

void AES::mixColumns()
{
    for (int j = 0; j < Nb; j++) {
        quint8 s0 = state[0][j];
        quint8 s1 = state[1][j];
        quint8 s2 = state[2][j];
        quint8 s3 = state[3][j];
        
        state[0][j] = gmul(0x02, s0) ^ gmul(0x03, s1) ^ s2 ^ s3;
        state[1][j] = s0 ^ gmul(0x02, s1) ^ gmul(0x03, s2) ^ s3;
        state[2][j] = s0 ^ s1 ^ gmul(0x02, s2) ^ gmul(0x03, s3);
        state[3][j] = gmul(0x03, s0) ^ s1 ^ s2 ^ gmul(0x02, s3);
    }
}

void AES::invMixColumns()
{
    for (int j = 0; j < Nb; j++) {
        quint8 s0 = state[0][j];
        quint8 s1 = state[1][j];
        quint8 s2 = state[2][j];
        quint8 s3 = state[3][j];
        
        state[0][j] = gmul(0x0e, s0) ^ gmul(0x0b, s1) ^ gmul(0x0d, s2) ^ gmul(0x09, s3);
        state[1][j] = gmul(0x09, s0) ^ gmul(0x0e, s1) ^ gmul(0x0b, s2) ^ gmul(0x0d, s3);
        state[2][j] = gmul(0x0d, s0) ^ gmul(0x09, s1) ^ gmul(0x0e, s2) ^ gmul(0x0b, s3);
        state[3][j] = gmul(0x0b, s0) ^ gmul(0x0d, s1) ^ gmul(0x09, s2) ^ gmul(0x0e, s3);
    }
}

quint8 AES::gmul(quint8 a, quint8 b)
{
    // Умножение в поле Галуа GF(2^8)
    quint8 p = 0;
    quint8 hi_bit_set;
    
    for (int i = 0; i < 8; i++) {
        if (b & 1) {
            p ^= a;
        }
        
        hi_bit_set = (a & 0x80);
        a <<= 1;
        if (hi_bit_set) {
            a ^= 0x1b; // x^8 + x^4 + x^3 + x + 1
        }
        
        b >>= 1;
    }
    
    return p;
}

void AES::bytesToState(const QByteArray &bytes)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < Nb; j++) {
            state[i][j] = static_cast<quint8>(bytes[i + 4 * j]);
        }
    }
}

void AES::bytesToState(const uint8_t* bytes)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < Nb; j++) {
            state[i][j] = bytes[i + 4 * j];
        }
    }
}

QByteArray AES::stateToBytes()
{
    QByteArray bytes;
    bytes.resize(4 * Nb);
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < Nb; j++) {
            bytes[i + 4 * j] = state[i][j];
        }
    }
    
    return bytes;
}

void AES::stateToBytes(uint8_t* bytes)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < Nb; j++) {
            bytes[i + 4 * j] = state[i][j];
        }
    }
}

QByteArray AES::padData(const QByteArray &data)
{
    // PKCS#7 padding
    int padLength = BLOCK_SIZE - (data.size() % BLOCK_SIZE);
    QByteArray result = data;
    
    for (int i = 0; i < padLength; i++) {
        result.append(static_cast<char>(padLength));
    }
    
    return result;
}

QByteArray AES::unpadData(const QByteArray &data)
{
    // PKCS#7 unpadding
    if (data.isEmpty()) {
        return data;
    }
    
    int padLength = static_cast<int>(data.at(data.size() - 1));
    
    if (padLength > BLOCK_SIZE || padLength <= 0) {
        m_lastError = "Неверное дополнение данных.";
        return data;
    }
    
    // Проверяем, что все байты дополнения имеют правильное значение
    for (int i = data.size() - padLength; i < data.size(); i++) {
        if (static_cast<int>(data.at(i)) != padLength) {
            m_lastError = "Неверное дополнение данных.";
            return data;
        }
    }
    
    return data.left(data.size() - padLength);
}

