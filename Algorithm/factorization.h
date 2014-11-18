#ifndef FACTORIZATION_AND_DISCRETE_LOGARITHM_H
#define FACTORIZATION_AND_DISCRETE_LOGARITHM_H

#include <QVector>
#include <QDebug>
#include "algorithm.h"
class LongInt;
class Point;
class Algorithm;
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

class Point:public Algorithm
{
private:
    LongInt _x,_y;
    static LongInt _mod;
    static LongInt _a;
    static LongInt _b;
    //y^2=x^3+ax+b;
public:
    Point(LongInt x,LongInt y);
    Point();

    static LongInt mod();
    static void setMod(LongInt);
    static void setA(LongInt _a);
    static void setB(LongInt);
    static void setElliptic_Curve(LongInt,LongInt);
    static LongInt a();
    static LongInt b();

    LongInt x();
    LongInt y();
    void setX(LongInt);
    void setY(LongInt);
    void setPoint(LongInt,LongInt);

    Point &operator =(const Point &b);
    bool  operator ==(const Point &b);
    Point operator +(Point b);
    Point operator -(Point b);
    Point operator *(LongInt);
    friend QDebug operator <<(QDebug ,Point);
};

#endif // FACTORIZATION_AND_DISCRETE_LOGARITHM_H
