#include "widget.h"
#include "Algorithm/factorization.h"
#include "stdlib.h"
#include <QApplication>
#include <QThread>
#include <QDebug>
#include <exception>
using namespace std;
int main(int argc, char *argv[])
{
    try
    {

    QApplication a(argc, argv);
    /*/
    for(LongInt i(1);i<500;++i)
    {
        qDebug()<<"=======================================";
        qDebug()<<Factorization::Pollard(i);
        a.thread()->sleep(1);
    }
    /*/
    //qDebug()<<LongInt(101)-LongInt(38);
    //qDebug()<<Algorithm::Modular_Multiplicative_Inverse(LongInt(38),LongInt(1019));//295
    //return 0;
    //while(1)
    {
        //qDebug()<<"result"<<
        qDebug()<<"Primitive"<<DiscreteLogarithm::Primitive(2,5,1019);
        qDebug()<<"Pollard"<<DiscreteLogarithm::Pollard(2,5,1019);
        //qDebug()<<"Primitive"<<DiscreteLogarithm::Primitive(2,3,19);
        //qDebug()<<"Pollard"<<DiscreteLogarithm::Pollard(2,3,19);
        //a.thread()->sleep(4);
    }
    return 0;
    //
    Widget w;
    w.show();
    return a.exec();

    }
    catch(...)
    {
        //qDebug()<<"main.cpp:Error ";
    }

    return 0;
}

void QObject::TimeEvent(QTimerEvent *)
{

}
