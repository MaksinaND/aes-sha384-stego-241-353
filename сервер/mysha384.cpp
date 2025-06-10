#include "mysha384.h"
#include <QtEndian>
#include <QDebug>

// Константы для SHA-384/512 (первые 64 простых числа)
const quint64 MySHA384::k[80] = {
    0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL, 0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL,
    0x3956c25bf348b538ULL, 0x59f111f1b605d019ULL, 0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL,
    0xd807aa98a3030242ULL, 0x12835b0145706fbeULL, 0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL,
    0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL, 0x9bdc06a725c71235ULL, 0xc19bf174cf692694ULL,
    0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL, 0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL,
    0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL, 0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL,
    0x983e5152ee66dfabULL, 0xa831c66d2db43210ULL, 0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL,
    0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL, 0x06ca6351e003826fULL, 0x142929670a0e6e70ULL,
    0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL, 0x4d2c6dfc5ac42aedULL, 0x53380d139d95b3dfULL,
    0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL, 0x81c2c92e47edaee6ULL, 0x92722c851482353bULL,
    0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL, 0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL,
    0xd192e819d6ef5218ULL, 0xd69906245565a910ULL, 0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL,
    0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL, 0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL,
    0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL, 0x5b9cca4f7763e373ULL, 0x682e6ff3d6b2b8a3ULL,
    0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL, 0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL,
    0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL, 0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL,
    0xca273eceea26619cULL, 0xd186b8c721c0c207ULL, 0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL,
    0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL, 0x113f9804bef90daeULL, 0x1b710b35131c471bULL,
    0x28db77f523047d84ULL, 0x32caab7b40c72493ULL, 0x3c9ebe0a15c9bebcULL, 0x431d67c49c100d4cULL,
    0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL, 0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL
};

MySHA384::MySHA384()
{
    // Инициализационные векторы для SHA-384
    reset();
}

void MySHA384::reset()
{
    h[0] = 0xcbbb9d5dc1059ed8ULL;
    h[1] = 0x629a292a367cd507ULL;
    h[2] = 0x9159015a3070dd17ULL;
    h[3] = 0x152fecd8f70e5939ULL;
    h[4] = 0x67332667ffc00b31ULL;
    h[5] = 0x8eb44a8768581511ULL;
    h[6] = 0xdb0c2e0d64f98fa7ULL;
    h[7] = 0x47b5481dbefa4fa4ULL;
}

QByteArray MySHA384::hash(const QByteArray &message)
{
    reset();
    QByteArray padded = padMessage(message);
    const quint8 *data = reinterpret_cast<const quint8*>(padded.constData());
    size_t blocks = padded.size() / 128;

    for (size_t i = 0; i < blocks; i++) {
        processChunk(data + i * 128);
    }

    // Для SHA-384 берем только первые 48 байт (первые 6 значений h)
    QByteArray result(48, 0);
    quint8 *ptr = reinterpret_cast<quint8*>(result.data());

    for (int i = 0; i < 6; i++) {
        qToBigEndian(h[i], ptr);
        ptr += 8;
    }

    return result;
}

QByteArray MySHA384::padMessage(const QByteArray &message)
{
    QByteArray padded = message;
    quint64 bitLength = message.size() * 8;

    // Добавляем бит '1'
    padded.append(static_cast<char>(0x80));

    // Добавляем нули до длины ≡ 112 mod 128
    int paddingLen = 112 - (padded.size() % 128);
    if (paddingLen < 0) paddingLen += 128;
    padded.append(QByteArray(paddingLen, 0));

    // Добавляем длину сообщения в битах (128 бит)
    QByteArray lengthBytes(16, 0);
    qToBigEndian(bitLength, reinterpret_cast<uchar*>(lengthBytes.data()) + 8);
    padded.append(lengthBytes);

    return padded;
}

void MySHA384::processChunk(const quint8 *chunk)
{
    quint64 w[80];

    // Преобразуем входные данные в массив 64-битных слов
    for (int i = 0; i < 16; i++) {
        w[i] = qFromBigEndian<quint64>(chunk + i * 8);
    }

    // Расширяем массив сообщений
    for (int i = 16; i < 80; i++) {
        quint64 s0 = rotateRight(w[i-15], 1) ^ rotateRight(w[i-15], 8) ^ shiftRight(w[i-15], 7);
        quint64 s1 = rotateRight(w[i-2], 19) ^ rotateRight(w[i-2], 61) ^ shiftRight(w[i-2], 6);
        w[i] = w[i-16] + s0 + w[i-7] + s1;
    }

    // Инициализация рабочих переменных
    quint64 a = h[0];
    quint64 b = h[1];
    quint64 c = h[2];
    quint64 d = h[3];
    quint64 e = h[4];
    quint64 f = h[5];
    quint64 g = h[6];
    quint64 h_val = h[7];

    // Основной цикл сжатия
    for (int i = 0; i < 80; i++) {
        quint64 S1 = rotateRight(e, 14) ^ rotateRight(e, 18) ^ rotateRight(e, 41);
        quint64 ch = (e & f) ^ ((~e) & g);
        quint64 temp1 = h_val + S1 + ch + k[i] + w[i];
        quint64 S0 = rotateRight(a, 28) ^ rotateRight(a, 34) ^ rotateRight(a, 39);
        quint64 maj = (a & b) ^ (a & c) ^ (b & c);
        quint64 temp2 = S0 + maj;

        h_val = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    // Обновляем хеш-значение
    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
    h[5] += f;
    h[6] += g;
    h[7] += h_val;
}

inline quint64 MySHA384::rotateRight(quint64 x, int n)
{
    return (x >> n) | (x << (64 - n));
}

inline quint64 MySHA384::shiftRight(quint64 x, int n)
{
    return x >> n;
}
