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
    static LongInt Pollard(LongInt,LongInt,LongInt);
    static LongInt Index(LongInt, LongInt, LongInt);
private:
    static void new_iter(LongInt &u, LongInt &v, LongInt& z, const LongInt *a=NULL, const LongInt *b=NULL, const LongInt *mod=NULL);
};

#endif // DISCRETE_LOGARITHM_H
