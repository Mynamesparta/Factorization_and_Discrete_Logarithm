#include "discrete_logarithm.h"

DiscreteLogarithm::DiscreteLogarithm()
{
}

LongInt DiscreteLogarithm::Primitive(LongInt g,LongInt b,LongInt n)
{
    if(g>=n||b>=n)
    {
        return (-LongInt(0));
    }
    LongInt _g=1;
    LongInt k=0;
    while(1)
    {
        _g*=g;
        _g=_g%n;
        ++k;
        if(_g==b)
        {
            return k;
        }
        if(_g==1)
        {
            return (-LongInt(0));
        }
    }
}

LongInt DiscreteLogarithm::Shank(LongInt g,LongInt b,LongInt n)
{
    qDebug()<<n<<(Algorithm::Agrawal_Kayal_Saxena(n)?"prime":"");
    LongInt _g(1),g_a,i(1),j,begin;
    LongInt a=LongInt::Sqrt(n-1)+1;
    qDebug()<<"a="<<a;
    QVector<LongInt> L_1,L_2;
    L_1<<1;
    //L_2<<b;
    qDebug()<< (g_a=Modular_exponentiation(g,n,a));
    //g_a=(g^a)%n;

    for(;i<a;++i)
    {
        _g*=g_a;
        _g=_g%n;
        if(_g==1)
            break;
        L_1<<_g;
    }
    _g=b;
    begin=_g;
    qDebug()<<L_1;
    for(j=0;j<L_1.length();++j)
    {
        qDebug()<<L_1[j.toInt()]<<"?"<<_g;
        if(L_1[j.toInt()]==_g)
        {
            qDebug()<<"Test:"<<g<<"^"<<(a*j)<<" mod"<<n<<"="<<((g^(a*j ))%n)<<"=="<<b;
            return (a*j );
        }
    }
    for(i=1;i<a;++i)
    {
        _g*=g;
        _g=_g%n;
        //L_2<<_g;
        qDebug()<<"_g="<<_g;
        if(_g==begin)
        {
            return (-LongInt(0));
        }
        for(j=0;j<L_1.length();++j)
        {
            qDebug()<<L_1[j.toInt()]<<"?"<<_g;
            if(L_1[j.toInt()]==_g)
            {
                qDebug()<<"Test:"<<g<<"^"<<(a*j - i)<<" mod"<<n<<"="<<((g^(a*j - i))%n)<<"=="<<b;
                return (a*j - i);
            }
        }
    }
    qDebug()<<L_1;
    return -LongInt(0);
}
