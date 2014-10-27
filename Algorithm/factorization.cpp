#include "factorization.h"

Factorization::Factorization()
{

}

Factorization::~Factorization()
{

}

QVector<LongInt> Factorization::Fermat(LongInt n)
{
    QVector<LongInt> result;
    while(n.number.last()%2==0)
    {
        n/=2;
        result<<2;
    }
    if(n==1)
    {
        return result;
    }
    if(Algorithm::Agrawal_Kayal_Saxena(n))
    {
        result<<n;
        return result;
    }
    LongInt n_2=n/2;
    LongInt x=LongInt::Sqrt(n);
    LongInt y(0);
    LongInt r_k(0);
    while(1)
    {
        if(x+y>n_2)
        {
            result<<n;
            return result;
        }
        r_k=n + y*y- x*x ;
        if(!r_k.minus&&r_k>0)
        {
            x+=1;
            continue;
        }
        if(r_k.minus&&r_k>0)
        {
            y+=1;
            continue;
        }
        if(r_k==0)
        {
            result<<Fermat(x-y)<<Fermat(x+y);
            qDebug()<<"result="<<result;
            return result;
        }
    }
}

QVector<LongInt> Factorization::World_of_Test(LongInt a)
{
    QVector<LongInt> result;
    a.number<<39<<-387;
    a.normalization();
    qDebug()<<(LongInt("5439")-LongInt("786548"));
    result<<a;//(LongInt("675438")-LongInt("786549"));
    return result;
}
