#ifndef FACTORIZATION_AND_DISCRETE_LOGARITHM_H
#define FACTORIZATION_AND_DISCRETE_LOGARITHM_H

#include <QVector>

#include "algorithm.h"
class LongInt;
class Factorization:public Algorithm
{
public:
    Factorization();
    ~Factorization();

    //========================================
    static QVector<LongInt> Fermat(LongInt);
    static QVector<LongInt> Pollard(LongInt);
    static QVector<LongInt> Lenstra(LongInt);
    static QVector<LongInt> World_of_Test(LongInt);
};

#endif // FACTORIZATION_AND_DISCRETE_LOGARITHM_H
