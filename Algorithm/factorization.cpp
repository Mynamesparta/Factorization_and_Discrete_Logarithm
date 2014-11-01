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
        qDebug()<<n;
        result<<n;
        return result;
    }
    else
    {
        qDebug()<<n;
    }
    LongInt n_2=n/2;
    LongInt x=LongInt::Sqrt(n);
    LongInt y(0);
    LongInt r_k(0);
    while(1)
    {
        if(x+y > n_2)
        {
            result<<n;
            return result;
        }
        //r_k=n + y*y - x*x ;
        r_k=n;
        qDebug()<<"Hello-6";
        r_k+=y*y;
        qDebug()<<r_k<<x*x;
        r_k-=x*x;
        qDebug()<<r_k;
        if(r_k>LongInt(0))
        {
            x+=1;
            continue;
        }
        if(r_k<LongInt(0))
        {
            y+=1;
            continue;
        }
        if(r_k==0)
        {
            qDebug()<<"Hello-9";
            result<<Fermat(x-y)<<Fermat(x+y);
            qDebug()<<"result="<<result;
            return result;
        }
    }
    return result;
}

QVector<LongInt> Factorization::World_of_Test(LongInt a)
{
    for(LongInt i(1);i<1000;++i)
    {
        if(Algorithm::Agrawal_Kayal_Saxena(i))
        {
            qDebug()<<i<<"prime";
        }
        else qDebug()<<i;
    }
    QVector<LongInt> result;
    a=        LongInt("78");
    a.minus=true;
    LongInt b=LongInt("4");
    b.minus=true;
    qDebug()<<a%b;
    //
    return result;
}
