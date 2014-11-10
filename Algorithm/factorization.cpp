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
    if(Agrawal_Kayal_Saxena(n))
    {
        //qDebug()<<n;
        result<<n;
        return result;
    }
    else
    {
        //qDebug()<<n;
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
        r_k+=y*y;
        //qDebug()<<r_k<<x*x;
        r_k-=x*x;
        if(r_k>LongInt(0))
        {
            ++x;
            continue;
        }
        if(r_k<LongInt(0))
        {
            ++y;
            continue;
        }
        if(r_k==0)
        {
            qDebug()<<x<<y;
            result<<Fermat(x-y)<<Fermat(x+y);
            //qDebug()<<"result="<<result;
            return result;
        }
    }
    return result;
}

QVector<LongInt> Factorization::Pollard(LongInt n)
{
    const int t=100;

    static int c=1;
    QVector<LongInt> result,_result;
    while(n.number.last()%2==0)
    {
        n/=2;
        result<<2;
        qDebug()<<"( 2 )";
    }
    //
    if(n==1)
    {
        return result;
    }
    if(Agrawal_Kayal_Saxena(n))
    {
        result<<n;
        return result;
    }

    LongInt a,b;
    LongInt hcd;
    LongInt i;

    _result<<n;
    while(!_result.isEmpty())//знаходження всіх дільників
    {
        a=2;
        b=2;
        n=_result.takeFirst();
        i=1;
        while(1)//знаходження ділника числа
        {
            a=(a^2+c) % n;//f(x)=x^2 + c, c - const
            b=(b^2+c) % n;
            b=(b^2+c) % n;
            hcd=HCD(b-a,n);
            if(hcd>1&&hcd<n)
            {
                c=1;
                if(Agrawal_Kayal_Saxena(hcd))
                {
                    result<<hcd;
                    qDebug()<<hcd;
                }
                else
                {
                    _result<<hcd;
                }
                n/=hcd;
                if(Agrawal_Kayal_Saxena(n))
                {
                    result<<n;
                    qDebug()<<n;
                }
                else
                {
                    _result<<n;
                }
                break;
            }
            if(++i>=t)
            {
                if(c==1)
                {
                    qDebug()<<"factorization.cpp:Pollard search f(x) for"<<n;
                }
                c+=1;//+2*(c/10);
                qDebug()<<"factorization.cpp:Pollard c="<<c;
                a=2;
                b=2;
                i=1;
                if(c>=100)
                {
                    qDebug()<<n<<"- prime ?";
                    result<<n;
                    break;
                }
            }
        }

    }
    return result;
}

QVector<LongInt> Factorization::Lenstra(LongInt n)
{
    QVector<LongInt> result;
    LongInt s=LongInt::Sqrt_n(n,3)+1;
    //-----------
    LongInt r(1);
    //-----------
    LongInt q;
    q=Modular_Multiplicative_Inverse(r,s);
    qDebug()<<n<<r<<s<<q;
    LongInt r_mod=(q*n)%s;
    qDebug()<<"r_mod"<<r_mod;
    LongInt i(1);
    LongInt a[3],b[3],c[3];
    for(;r<s;++r)
    {
        if(HCD(r,s)!=1)
        {
            continue;
        }
        b[0]=0;c[0]=0;
        a[1]=(r_mod*q)%s;
        b[1]=1;
        c[1]=((n-r*r_mod)/s * q)%s;
        qDebug()<<"a[0]="<<a[0];
        qDebug()<<"a[1]="<<a[1];
        qDebug()<<"b[0]="<<b[0];
        qDebug()<<"b[1]="<<b[1];
        qDebug()<<"c[0]="<<c[0];
        qDebug()<<"c[1]="<<c[1];
        qDebug()<<"start";
        i=1;
        while(1)
        {
            ++i;
            qDebug()<<"i="<<i;
            if(i.last()%2)
            {
                qDebug()<<a[0]<<a[1];
                qDebug()<<( q=(a[0]%a[1]) );
                qDebug()<<"q="<<q;
                a[2]=a[0]-q*a[1];
                a[0]=a[1];
                a[1]=a[2];

                b[2]=b[0]-q*b[1];
                b[0]=b[1];
                b[1]=b[2];

                c[2]=(c[0]-q*c[1])%s;
                c[0]=c[1];
                c[1]=c[2];
            }
            else
            {

            }
            qDebug()<<"a[0]="<<a[0];
            qDebug()<<"a[1]="<<a[1];
            qDebug()<<"b[0]="<<b[0];
            qDebug()<<"b[1]="<<b[1];
            qDebug()<<"c[0]="<<c[0];
            qDebug()<<"c[1]="<<c[1];
            if(a[1]==0)
            {
                break;
            }
            if(i==10)
            {
                break;
            }
        }
    }
    //
    return result;
}

QVector<LongInt> Factorization::World_of_Test(LongInt a)
{
    /*/
    for(LongInt i(1);i<1000;++i)
    {
        qDebug()<<i<<"="<<Factorization::Fermat(i);
    }
    /*/
    qDebug()<<Factorization::Fermat(995);
    QVector<LongInt> result;
    //result<<(LongInt(102)-LongInt(97));
    /*/
    a=        LongInt("78");
    a.minus=true;
    LongInt b=LongInt("4");
    b.minus=true;
    //qDebug()<<a%b;
    /*/
    return result;
}
