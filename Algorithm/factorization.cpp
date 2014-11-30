#include "factorization.h"
#define qF QString("factorization.cpp:")
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
        //qDebug()<<"( 2 )";
    }
    while(n%3==0)
    {
        n/=3;
        result<<3;
        //qDebug()<<qF+"( 3 )";
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
                    while(n%hcd==0)
                    {
                        result<<hcd;
                        //qDebug()<<hcd;
                        n/=hcd;
                    }
                }
                else
                {
                    _result<<hcd;
                }
                //n/=hcd;
                if(n==1)
                    break;
                if(Agrawal_Kayal_Saxena(n))
                {
                    result<<n;
                    //qDebug()<<n;
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
                    //qDebug()<<"factorization.cpp:Pollard search f(x) for"<<n;
                }
                c+=1;//+2*(c/10);
                //qDebug()<<"factorization.cpp:Pollard c="<<c;
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
    QVector<LongInt> result,factorization;
    while(n.number.last()%2==0)
    {
        n/=2;
        result<<2;
        qDebug()<<"( 2 )";
    }
    while(n%3==0)
    {
        n/=3;
        result<<3;
        qDebug()<<"( 3 )";
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
    LongInt B(10000);
    LongInt a,b,_hcd;
    Point P_0,P_k;
    factorization<<n;
    while(!factorization.isEmpty())
    {
        //====================initialization
        n=factorization.takeFirst();
        Point::setMod(n);
        while(1)
        {
            P_0.setPoint(Random(1,n-1),Random(0,n-1));
            a=Random(0,n-1);
            b=((P_0.y()^2)-(P_0.x()^3)-a*P_0.x())%n;
            _hcd=HCD(n,(a^3)*4+(b^2)*27);
            if(_hcd==n)
                continue;
            if(_hcd==1)
            {
                qDebug()<<"y^2 = x^3 + "<<a<<"x + "<<b;
                qDebug()<<P_0;
                Point::setElliptic_Curve(a,b);
                break;
            }
            //======1<_hcd<n===========================
            qDebug()<<"factorization.cpp: Lenstre HCD"<<_hcd;
            if(Algorithm::Agrawal_Kayal_Saxena(_hcd))
            {
                result<<_hcd;
            }
            else
            {
                factorization<<_hcd;
            }
            _hcd=n/_hcd;
            qDebug()<<"factorization.cpp: Lenstre HCD"<<_hcd;
            if(Algorithm::Agrawal_Kayal_Saxena( _hcd))
            {
                result<<_hcd;
            }
            else
            {
                factorization<<_hcd;
            }
            goto _continue;
            //=========================================
        }
        //==================================
        P_k=P_0;
        for(LongInt i(2) ;i<B;++i)
        {
            if(Algorithm::Agrawal_Kayal_Saxena(i))
            {
                a=1;
                while(a<B)
                {
                    P_k=P_k*i;
                    a*=i;
                    _hcd=Point::divisor();
                    if(_hcd!=0)
                    {
                        qDebug()<<result<<factorization;
                        qDebug()<<"factorization.cpp: Lenstre HCD"<<_hcd;
                        if(Algorithm::Agrawal_Kayal_Saxena( _hcd))
                        {
                            result<<_hcd;
                        }
                        else
                        {
                            factorization<<_hcd;
                        }
                        qDebug()<<result<<factorization;
                        _hcd=n/_hcd;
                        qDebug()<<"factorization.cpp: HCD"<<_hcd;
                        if(Algorithm::Agrawal_Kayal_Saxena( _hcd))
                        {
                            result<<_hcd;
                        }
                        else
                        {
                            factorization<<_hcd;
                        }
                        goto _continue;
                    }
                }
            }
        }
        factorization<<n;
        _continue:;
    }
    return result;
}

LongInt Factorization::Generator(LongInt n)
{
    LongInt rand,totient=Algorithm::Eulers_totient(n);
    QVector<LongInt> factorization=Factorization::Lenstra(totient);
    qDebug()<<qF<<"factorization="<<factorization;
    QVector<LongInt>::const_iterator iter;
    while(1)
    {
        rand=Random(2,n-1);
        /*/
        static int Debug=0;
        switch(Debug)
        {
        case 0:
            rand=64;
            Debug++;
            break;
        case 1:
            rand=8;
            Debug++;
            break;
        case 2:
            rand=99;
            Debug++;
            break;
        case 3:
            rand=76;
            Debug++;
            break;
        case 4:
            rand=70;
            Debug++;
            break;
        }
        /*/
        iter=factorization.constBegin();
        while(1)
        {
            //qDebug()<<qF<<rand<<Modular_exponentiation(rand,n,totient/(*iter));
            if(Modular_exponentiation(rand,n,totient/(*iter))==1)
            {
                break;
            }
            iter++;
            if(iter==factorization.constEnd())
            {
                goto _break;
            }
        }
    };
    _break:;
    return rand;
}

QVector<LongInt> Factorization::Square(LongInt N)
{
    //===initialization======================
    QVector<LongInt> result,factorization;
    QVector<LongInt> Base,V_x_base,V_x,S_x,S_i;
    QVector<LongInt>::const_iterator iter;
    LongInt* modular_sqrt;
    //=======================================
    while(N.number.last()%2==0)
    {
        N/=2;
        result<<2;
        qDebug()<<"( 2 )";
    }
    if(N==1)
    {
        return result;
    }
    if(Agrawal_Kayal_Saxena(N))
    {
        result<<N;
        return result;
    }
    else
    {
        factorization<<N;
    }
    LongInt sqrt_N;
    static LongInt p,d;
    static LongInt i;
    static int j,k;
    while(!factorization.isEmpty())
    {
        N=factorization.takeFirst();
        d=2;
        p=1;
        Base.clear();
        V_x_base.clear();
        V_x.clear();
        S_x.clear();
        S_i.clear();
        Base<<2;
        while(d<N&&p<N)
        {
            p+=2;
            if(Agrawal_Kayal_Saxena(p) )
            {
                //qDebug()<<"factorization.cpp:Square "<<_base<<n<<(n-1)/2<<"="<<(Modular_exponentiation(_base,n,(n-1)/2));
                if(Modular_exponentiation(N,p,(p-1)/2)==1)
                {
                    Base<<p;
                    d*=p;
                }
            }
            if(d==N)
            {
                return result+Base;
            }
        }
        sqrt_N=LongInt::Sqrt_n(N-1,2)+1;
        //qDebug()<<N;
        //qDebug()<<"factorization.cpp:Square Base-"<<Base;
        //qDebug()<<"factorization.cpp:Sqrt(N)="<<sqrt_N;
        for(i=0;i<100;++i)
        {
            V_x_base<<(((sqrt_N+i)^2)-N);
            V_x<<V_x_base.last();
            //qDebug()<<"factorization.cpp:Y("<<i<<")="<<Y_x.last();
        }
        for(i=1;i<V_x.length();i+=2)
        {
            V_x[i.toInt()]/=2;
        }
        iter=Base.constBegin();
        iter++;
        for(;iter<Base.constEnd();iter++)
        {
            //qDebug()<<"factorization.cpp:current base:"<< *iter;
            modular_sqrt=Modular_Sqrt(N,*iter);
            i=(modular_sqrt[0]-sqrt_N)%(*iter);
            i.normalization();
            i=(i<LongInt()?(i+*iter):i);
            //qDebug()<<"factorization.cpp:current Index"<<i;
            while(i<V_x.length())
            {
                V_x[i.toInt()]/=*iter;
                //qDebug()<<i<<V_x[i.toInt()];
                i+=*iter;
            }
            if(modular_sqrt[0]!=modular_sqrt[1])
            {
                i=(modular_sqrt[1]-sqrt_N)%(*iter);
                i.normalization();
                i=(i<LongInt()?i+*iter:i);
                //qDebug()<<"factorization.cpp:current Index"<<i;
                while(i<V_x.length())
                {
                    V_x[i.toInt()]/=*iter;
                    //qDebug()<<i<<V_x[i.toInt()];
                    i+=*iter;
                }
            }
            delete modular_sqrt;
            delete (modular_sqrt+1);
        }
        //qDebug()<<V_x;
        QVector<QVector<bool>> matrix(Base.length());
        for(i=0;i<V_x.length();++i)
        {
            if(V_x[i.toInt()]==1)
            {
                qDebug()<<"factorization.cpp:гладке число(індекс число)-"<<i<<V_x_base[i.toInt()];
                S_x<<V_x_base[i.toInt()];
                S_i<<i;
                for(j=0;j<Base.length();++j)
                {
                    if(V_x_base[i.toInt()]%Base[j]==0)
                    {
                        matrix[j]<<1;
                    }
                    else
                    {
                        matrix[j]<<0;
                    }
                }
            }
        }
        bool S[S_x.length()];
        /*/
        for(j=0;j<matrix.length();++j)
        {
            qDebug()<<matrix[j];
        }
        qDebug()<<"----------------------------";
        /*/
        //==============знаходження=матриці=S============
        for(j=0;j<S_x.length();++j)//стовбчик
            for(i=j;i<matrix.length();++i)//рядочок
            {
                if(matrix[i.toInt()][j])
                {
                    matrix.insert(j,matrix.takeAt(i.toInt()));
                    for(i=0;i<matrix.length();++i)
                    {
                        if(i!=j)
                        {
                            if(matrix[i.toInt()][j])
                            {
                                for(k=j;k<S_x.length();++k)
                                {
                                    matrix[i.toInt()][k]=(matrix[i.toInt()][k]+matrix[j][k])%2;
                                }
                            }
                        }
                    }
                    break;
                }
            };
        /*/
        for(j=0;j<matrix.length();++j)
        {
            qDebug()<<matrix[j];
        }
        /*/
        for(i=0;i<Base.length()-1;++i)
        {
            S[i.toInt()]=matrix[i.toInt()][S_x.length()-1];
            //qDebug()<<"S:"<<S[i.toInt()];
        }
        if(!S_x.isEmpty())
            S[S_x.length()-1]=1;
        else
        {
            qDebug()<<qF+"somithing wrong:(";
            return result;
        }
        //==============знаходження=дільника=============
        d=1;
        p=1;
        for(j=0;j<S_x.length();++j)
        {
            if(S[j])
            {
                qDebug()<< (d*=S_x[j]);
                qDebug()<< (p*=((sqrt_N+S_i[j])));
            }
        }
        modular_sqrt=Modular_Sqrt(d,N);
        if(p==modular_sqrt[0])
            d=modular_sqrt[1];
        else
            d=modular_sqrt[0];
        delete modular_sqrt;
        delete (modular_sqrt+1);
        //qDebug()<<p<<d<<N;
        i=HCD(+(p-d),N);
        if(Algorithm::Agrawal_Kayal_Saxena( i))
        {
            result<<i;
        }
        else
        {
            factorization<<i;
        }
        //qDebug()<<result<<factorization;
        i=N/i;
        //qDebug()<<"factorization.cpp: HCD"<<i;
        if(Algorithm::Agrawal_Kayal_Saxena(i))
        {
            result<<i;
        }
        else
        {
            factorization<<i;
        }
        //===============================================
        //qDebug()<<result<<factorization;
        //return result;
    }//while(!factorization.isEmpty)
    return result;
}

QVector<LongInt> Factorization::World_of_Test(LongInt a)
{
    LongInt* paint=Modular_Sqrt(15347,17);
    qDebug()<<paint[0]<<paint[1];
    //Factorization::Lenstra(96);
    /*/
    Point::setMod(23);
    Point::setElliptic_Curve(1,1);
    //Point(3,-10)+Point(11,3);
    //Point(0,1)+Point(0,1);
    /*/
    delete paint;
    delete (paint+1);
    //qDebug()<<paint[1];//<<paint[0];
    QVector<LongInt> result;
    return result;
}
//========================================================private=metod==============================================

LongInt* Factorization::Modular_Sqrt(const LongInt& N,const LongInt& mod)
{\
    register LongInt i=0;
    register LongInt i_2;
    register LongInt N_j=N%mod;
    //qDebug()<<"N_j"<<N<<mod<<N_j;
    LongInt* result=new LongInt[2];
    while(i<mod)
    {
        i_2=i^2;
        if(i_2<N_j)
        {
            ++i;
        }
        while(i_2>N_j)
        {
            N_j+=mod;
        }
        if(i_2==N_j)
        {
            result[0]=i;
            //qDebug()<<"factorization.cpp:Modular Sqrt: result 0"<<i;
            break;
        }
    }
    if(mod==2)
    {
        result[0]=i;
        return result;
    }
    ++i;
    while(i<mod)
    {
        i_2=i^2;
        if(i_2<N_j)
        {
            ++i;
        }
        while(i_2>N_j)
        {
            N_j+=mod;
        }
        if(i_2==N_j)
        {
            result[1]=i;
            //qDebug()<<"factorization.cpp:Modular Sqrt: result 1"<<i;
            break;
        }
    }
    return result;

}

//========================================================class=Point================================================
LongInt Point::_mod=-LongInt(0);
LongInt Point::_a=0;
LongInt Point::_b=0;
LongInt Point::_divisor=0;
Point::Point(LongInt x,LongInt y):Algorithm(),_x(x),_y(y)
{

}

Point::Point():Algorithm(),_x(0),_y(0)
{

}

//=============static==================
void Point::setA(LongInt A)
{
    _a=(A%mod());
}

void Point::setB(LongInt B)
{
    _b=B%mod();
}

void Point::setElliptic_Curve(LongInt A,LongInt B)
{
    _a=A%mod();
    _b=B%mod();
}

LongInt Point::a()
{
    return _a;
}

LongInt Point::b()
{
    return _b;
}

LongInt Point::divisor()
{
    qDebug()<<"factorization.cpp:divisor-"<<_divisor;
    LongInt h=_divisor;
    _divisor=0;
    return h;
}

void Point::setMod(LongInt mod)
{
    if(mod<=0)
        _mod=-LongInt(1);
    else
        _mod=mod;
}

LongInt Point::mod()
{
    return _mod;
}
//=====================================
LongInt Point::x() const
{
    return _x;
}

LongInt Point::y()const
{
    return _y;
}

void Point::setX(LongInt x)
{
    _x=x%mod();
}

void Point::setY(LongInt y)
{
    _y=y%mod();
}

void Point::setPoint(LongInt x,LongInt y)
{
    _x=x%mod();
    _y=y%mod();
}


Point& Point::operator =(const Point& b)
{
    if(this==&b)
    {
        return *this;
    }
    this->_x=b._x;
    this->_y=b._y;
    return *this;
}

bool Point::operator ==(const Point &b)const
{
    if(this->_x==b._x&&this->_y==b._y)
    {
        return true;
    }
    else return false;
}

bool  Point::operator ==( LongInt b)
{
    if( b==0 &&_x==0&&_y==0)
        return true;
    else
        false;
}

Point Point::operator +(const Point& R)const
{
    if(x()==0&&y()==0)
    {
        return R;
    }
    if(R.x()==0&&R.y()==0)
    {
        return *this;
    }
    static LongInt tg,inverse;
    static bool* search_divisor;
    search_divisor=new bool(true);
    if(*this==R)
    {
        inverse=Modular_Multiplicative_Inverse(this->y()*2,mod(),search_divisor);
        qDebug()<<"inverse="<<inverse;
        if(!*search_divisor)
        {
            qDebug()<<"find divisor of "<<mod()<<":"<<inverse;
            delete search_divisor;
            Point::_divisor=inverse;
            return Point(0,0);
        }
        tg=(+((this->x()^2)*3 + a()))*inverse;
        qDebug()<<"Q==R:tg="<<tg;
    }//                   !! +?-
    else
    {
        inverse=Modular_Multiplicative_Inverse( +(this->x()-R.x()) , mod(),search_divisor);
        qDebug()<<"inverse="<<inverse;
        if(!*search_divisor)
        {
            qDebug()<<"find divisor of "<<mod()<<":"<<inverse;
            delete search_divisor;
            Point::_divisor=inverse;
            return Point(0,0);
        }
        tg=inverse*( (this->x()>=R.x()) ? (this->y() - R.y()) : ( R.y()-this->y()) );
        qDebug()<<"Q!=R:tg="<<tg;
    }// +(x)~|x|
    delete search_divisor;
    tg=tg%mod();
    Point result;

    result.setX(((tg^2) - this->_x -R._x)%_mod);
    result.setY((tg*(_x-result._x) - _y)%_mod);

    return result;
}
Point Point::operator -( Point b)
{
    b.setY(-b.y());
    return   *this+b;
}
Point Point::operator *(LongInt k)const
{
    if(k==2)
    {
        return *this+*this;
    }
    if(k==0)
    {
        qDebug()<<"factorization.cpp:Error in operator* k = 0, Point = "<<*this;
        throw *this;
    }
    QVector<bool> Binary_number;
    while(k!=0)
    {
        if(k.last()%2==0)
        {
            Binary_number<<0;
        }
        else
        {
            Binary_number<<1;
        }
        k/=2;
    }
    //qDebug()<<"Binary:"<<Binary_number;
    static Point a;
    Point result;
    a=*this;
    static LongInt x=1;
    //qDebug()<<"x="<<x;
    while(1)
    {
        if(Binary_number.takeFirst())
        {
            //qDebug()<<"result+a:";
            result=result+a;
            if(result==0)
            {
                return result;
            }
        }
        //qDebug()<<"x="<<x;
        if(Binary_number.isEmpty())
        {
            break;
        }
        //qDebug()<<"a+a:";
        a=a+a;
        x*=2;
    }
    //qDebug()<<"k="<<test;
    return result;
}

QDebug operator <<(QDebug qd,Point a)
{
    qd<<"Point("<<a.x()<<","<<a.y()<<")";
    return qd;
}
//==============================================

