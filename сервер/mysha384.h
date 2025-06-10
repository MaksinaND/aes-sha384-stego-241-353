#ifndef MYSHA384_H
#define MYSHA384_H

#include <QString>
#include <QByteArray>
#include <QtEndian>

class MySHA384
{
public:
    MySHA384();
    QByteArray hash(const QByteArray &message);

private:
    quint64 h[8]; // Инициализационные векторы для SHA-384

    // Константы для SHA-384
    static const quint64 k[80];

    void processChunk(const quint64 *chunk);
    QByteArray padMessage(const QByteArray &message);
    quint64 rotateRight(quint64 x, int n);
    quint64 shiftRight(quint64 x, int n);
};

#endif // MYSHA384_H
