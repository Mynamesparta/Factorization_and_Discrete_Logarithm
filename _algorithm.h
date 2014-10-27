#ifndef ALGORITHM_H
#define ALGORITHM_H
/*/
#include <QVector>
#include <QStack>
#include <QApplication>

#include <complex>
#include <math.h>

#include "LongNumber/longint.h"
#include "LongNumber/longdouble.h"
class LongInt;
class LongDouble;

struct Table;

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
private:
     static int Modular_Multiplicative_Inverse(int,int);
     static void FFT(QVector< std::complex<double> >&,bool);
     static LongInt HCD(LongInt,LongInt);
     static LongInt Modular_exponentiation(LongInt a,LongInt m, LongInt r);
     struct Table
     {
         int q,r;
     };
     static const int coef=8;
};
/*/


#endif // ALGORITHM_H
