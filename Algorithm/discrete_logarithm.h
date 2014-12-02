#ifndef DISCRETE_LOGARITHM_H
#define DISCRETE_LOGARITHM_H
#include "algorithm.h"
#include <QVector>
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
    static LongInt Pohlig_Hellman(LongInt,LongInt,LongInt);
    static LongInt Adleman(LongInt,LongInt,LongInt);

    static void create_answer_matrix(QVector<QVector<LongInt>>&,const QVector<LongInt>&,const LongInt,const LongInt&);
private:
    static void new_iter(LongInt &u, LongInt &v, LongInt& z, const LongInt *a=NULL, const LongInt *b=NULL, const LongInt *mod=NULL);
 };

#endif // DISCRETE_LOGARITHM_H
