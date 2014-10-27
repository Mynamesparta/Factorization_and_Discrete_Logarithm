#ifndef FACTORIZATION_AND_DISCRETE_LOGARITHM_H
#define FACTORIZATION_AND_DISCRETE_LOGARITHM_H

#include <QVector>

#include "algorithm.h"
class LongInt;
class Factorization
{
public:
    Factorization();
    ~Factorization();

    //========================================
    static QVector<LongInt> Fermat(LongInt);
};

#endif // FACTORIZATION_AND_DISCRETE_LOGARITHM_H
