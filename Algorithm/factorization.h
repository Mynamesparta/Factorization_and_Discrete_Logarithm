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
    static QVector<LongInt> Square(LongInt);
    static LongInt Generator(LongInt);
    static QVector<LongInt> World_of_Test(LongInt);
private:
    static LongInt* Modular_Sqrt(const LongInt&n, const LongInt &mod);
};

class Point:public Algorithm
{
private:
    LongInt _x,_y;
    static LongInt _mod;
    static LongInt _a;
    static LongInt _b;
    static LongInt _divisor;
    //y^2=x^3+ax+b;
public:
    Point(LongInt x,LongInt y);
    Point();

    static LongInt mod() ;
    static void setMod(LongInt);
    static void setA(LongInt _a);
    static void setB(LongInt);
    static void setElliptic_Curve(LongInt,LongInt);
    static LongInt a();
    static LongInt b();
    static LongInt divisor();

    LongInt x()const;
    LongInt y()const;
    void setX(LongInt);
    void setY(LongInt);
    void setPoint(LongInt,LongInt);

    Point &operator =(const Point &b);
    bool  operator ==(const Point &b) const;
    bool  operator ==(LongInt);
    Point operator +(const Point &b) const;
    Point operator -(Point b);
    Point operator *(LongInt) const;
    friend QDebug operator <<(QDebug ,Point);
};

#endif // FACTORIZATION_AND_DISCRETE_LOGARITHM_H
