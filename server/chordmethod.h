#ifndef CHORDMETHOD_H
#define CHORDMETHOD_H

#include <QObject>
#include <QVector>
#include <QPair>
#include <functional>

class ChordMethod : public QObject
{
    Q_OBJECT
public:
    explicit ChordMethod(QObject *parent = nullptr);

    QPair<double, int> solve(const QString& functionName, double a, double b, double epsilon, int maxIterations, QString& errorMessage);

private:
    std::function<double(double)> getFunction(const QString& name);
};

#endif // CHORDMETHOD_H


