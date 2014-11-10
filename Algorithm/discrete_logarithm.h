#ifndef DISCRETE_LOGARITHM_H
#define DISCRETE_LOGARITHM_H
#include "algorithm.h"
class Algorithm;
class LongInt;
class DiscreteLogarithm:public Algorithm
{
public:
    DiscreteLogarithm();
    static LongInt Primitive(LongInt,LongInt,LongInt);
    static LongInt Shank(LongInt,LongInt,LongInt);
};

#endif // DISCRETE_LOGARITHM_H
