#ifndef LONGINT_H
#define LONGINT_H
#include <QDebug>
#include <QVector>
#include <QStack>
#include <QApplication>

//#include "algorithm.h"
//#include "longdouble.h"

#include "complex"
#include "math.h"

struct Table;

class Algorithm;
class LongInt;
class LongDouble;
//====================================================LongInt======================
static LongInt (*current_algorithm)(LongInt,LongInt);
class LongInt
{
protected:
    static LongInt mod(LongInt,LongInt);
    static const int _baza_for_initializatio=2;
    static const int _baza=100;
public:
    LongInt();
    LongInt(QString);
    LongInt(int);
    
    static void setBaza(int new_baza=1);
    static void setAlgorithm(QString);
    static int baza_for_initializatio();
    static int baza();
    static LongInt Sqrt(LongInt);
    static LongInt Sqrt_n(LongInt,LongInt);

    void push_front(int num);
    void push_back(int num);
    void clear();
    void normalization();
    void _normalization();
    bool isEmpty();
    int  length();
    void resize(int); //Null

    virtual QString toString();
    int toInt();

    QVector<int> getVector_of_Number(int first=0, int renge=0 ,bool remove=1);
    //+++++++++++++++++++++++++++++operator+++++++++++++++++++++++++++++++++++++++
    LongInt  operator +(LongInt );
    LongInt  operator +(int );
    LongInt  operator -(LongInt );
    LongInt  operator -(int );
    LongInt& operator =(const LongInt );
    LongInt& operator =(const int );
    LongInt& operator +=(const LongInt );
    LongInt& operator +=(const int );
    LongInt& operator -=(const LongInt );
    LongInt& operator -=(const int );
    bool  operator >(LongInt);
    bool  operator >(int);
    bool  operator <(LongInt);
    bool  operator <(int);
    bool  operator ==(LongInt);
    bool  operator ==(int);
    bool  operator !=(LongInt);
    bool  operator !=(int);
    bool  operator >=(LongInt);
    bool  operator >=(int);
    bool  operator <=(LongInt);
    bool  operator <=(int);
    LongInt  operator <<(int);
    LongInt& operator <<=(int);
    LongInt operator >>(int);
    LongInt  operator *(LongInt);
    LongInt  operator *(int);
    LongInt& operator *=(LongInt);
    LongInt& operator *=(int b);
    LongInt  operator /(LongInt);
    LongInt  operator /(int);
    LongInt& operator /=(LongInt);
    LongInt& operator /=(int);
    LongInt  operator %(LongInt);
    LongInt  operator ^(LongInt);
    LongInt  operator ^(int);
    int &operator [](int);
    friend QDebug operator<<(QDebug,LongInt);
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    QVector<int> number;

    bool minus=0;
};
//====================================================LongDouble===================
class LongDouble:public LongInt
{
private:
    int _size=-1;
public:
    LongDouble();
    LongDouble(QString);
    LongDouble(int);

    virtual QString toString();
    void setSize(int);
    int size();

    LongDouble& operator =(const LongInt );
    LongDouble& operator =(const LongDouble );

};

struct Table;
//====================================================Algorithm====================
class Algorithm
{
public:
     static LongInt  Karatsuba(LongInt , LongInt );
     static LongInt  Toom_Cook(LongInt , LongInt );
     static LongInt  Schonhage(LongInt , LongInt );
     static LongInt  Strassen (LongInt , LongInt );

     static LongInt* Inverse_Number_Toom(LongInt,LongInt =0 );
     static LongInt* Toom(LongInt , LongInt );

     static bool Lehmer(LongInt, int r);
     static bool Miller_Rabin(LongInt, int);
     static bool Solovay_Strassen(LongInt, int);
     static bool Agrawal_Kayal_Saxena(LongInt);

     static LongInt  HelloWorldofTest(LongInt, LongInt );
     //static QVector<int> prime_numbers;
private:
     static int Modular_Multiplicative_Inverse(int,int);
     static void FFT(QVector< std::complex<double> >&,bool);
     static LongInt HCD(LongInt,LongInt);
     static LongInt Modular_exponentiation(LongInt a,LongInt m, LongInt r);
     static LongInt Eulers_totient(LongInt );
     struct Table
     {
         int q,r;
     };
     static const int coef=8;
};
//==================================================================================
#endif // LONGINT_H
