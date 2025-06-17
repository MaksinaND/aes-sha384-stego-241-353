#include "chordmethod.h"
#include <QtMath>

ChordMethod::ChordMethod(QObject *parent) : QObject(parent) {}

QPair<double, int> ChordMethod::solve(const QString& functionName, double a, double b, double epsilon, int maxIterations, QString& errorMessage)
{
    std::function<double(double)> func = getFunction(functionName);
    if (!func) {
        errorMessage = "Неизвестная функция: " + functionName;
        return qMakePair(0.0, 0);
    }

    if (func(a) * func(b) >= 0) {
        errorMessage = "Функция должна иметь разные знаки на концах интервала [a, b].";
        return qMakePair(0.0, 0);
    }

    double x = a;
    int iterations = 0;

    for (iterations = 0; iterations < maxIterations; ++iterations) {
        double fx = func(x);
        double fa = func(a);
        double fb = func(b);

        if (qAbs(fx) < epsilon) {
            errorMessage = "Корень найден с заданной точностью.";
            return qMakePair(x, iterations);
        }

        double next_x = b - fb * (b - a) / (fb - fa);

        if (func(a) * func(next_x) < 0) {
            b = next_x;
        } else {
            a = next_x;
        }
        x = next_x;
    }

    errorMessage = "Не удалось найти корень за максимальное количество итераций.";
    return qMakePair(x, iterations);
}

std::function<double(double)> ChordMethod::getFunction(const QString& name)
{
    if (name == "x^2 - 4") {
        return [](double x) { return x*x - 4; };
    } else if (name == "sin(x) - x/2") {
        return [](double x) { return qSin(x) - x/2; };
    } else if (name == "e^x - 3x") {
        return [](double x) { return qExp(x) - 3*x; };
    } else if (name == "x^3 - x - 1") {
        return [](double x) { return x*x*x - x - 1; };
    }
    return nullptr;
}


