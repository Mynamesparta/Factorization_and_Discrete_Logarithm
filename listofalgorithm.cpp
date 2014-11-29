#include "listofalgorithm.h"

ListofAlgorithm::ListofAlgorithm()
{
    //set("Fermat");
}
ListofAlgorithm::~ListofAlgorithm()
{

}

QString ListofAlgorithm::run_factorization(QString first)
{
    LongInt a(first);
    QString text;
    text="<h3>current algorithm:</h3> <h2>"+name_of_current_algorithm+"</h2>\n";
    timer.restart();
    //==================run=algorithm======
    QVector<LongInt>result((*current_algorithm_factorization)(a));
    qDebug()<<"listofalgorithm.cpp:run result="<<result;
    //=====================================
    text+="<h3>time:"+QString::number(timer.elapsed())+" ms </h3>\n<h3>";
    while(!result.isEmpty())
    {
        text+=result.takeFirst().toString();
        if(!result.isEmpty())
        {
            text+=", ";
        }
    }
    return text+"</h3>";
}

QString ListofAlgorithm::run_discrete_logarithm(QString first, QString second, QString third)
{
    LongInt g(first),b(second),n(third);
    QString text;
    text="<h3>current algorithm:</h3> <h2>"+name_of_current_algorithm+"</h2>\n";
    timer.restart();
    //==================run=algorithm======
    LongInt result=(*current_algorithm_logarithm)(g,b,n);
    qDebug()<<"listofalgorithm.cpp:run result="<<result;
    //=====================================
    text+="<h3>time:"+QString::number(timer.elapsed())+" ms </h3>\n<h3>";
    if((result.isEmpty())||(result.minus))
    {
        text+="NULL";
    }
    else
    {
        text+=result.toString();
    }
    return text+"</h3>";
}

QString ListofAlgorithm::getListofAlgorithm()
{
    return "Fermat fPollard Lenstra Square Primitive Shank dPollard World_of_Test";
}

int ListofAlgorithm::set(QString name )
{
    name_of_current_algorithm=name;
    if(name=="Fermat")
    {
        current_algorithm_factorization=&Factorization::Fermat;
        qDebug()<<"listofalgorithm.h:current algorithm \"Fermat\"";
        return 1;
    }
    if(name=="fPollard")
    {
        current_algorithm_factorization=&Factorization::Pollard;
        qDebug()<<"listofalgorithm.h:current algorithm \"fPollard\"";
        return 1;
    }
    if(name=="Lenstra")
    {
        current_algorithm_factorization=&Factorization::Lenstra;
        qDebug()<<"listofalgorithm.h:current algorithm \"Lenstra\"";
        return 1;
    }
    if(name=="Square")
    {
        current_algorithm_factorization=&Factorization::Square;
        qDebug()<<"listofalgorithm.h:current algorithm \"Square\"";
        return 1;
    }
    if(name=="World_of_Test")
    {
        current_algorithm_factorization=&Factorization::World_of_Test;
        qDebug()<<"listofalgorithm.h:current algorithm \"World_of_Test\"";
        return 1;
    }
    if(name=="Primitive")
    {
        current_algorithm_logarithm=&DiscreteLogarithm::Primitive;
        qDebug()<<"listofalgorithm.h:current algorithm \"Primitive\"";
        return 3;
    }
    if(name=="Shank")
    {
        current_algorithm_logarithm=&DiscreteLogarithm::Shank;
        qDebug()<<"listofalgorithm.h:current algorithm \"Shank\"";
        return 3;
    }
    if(name=="dPollard")
    {
        current_algorithm_logarithm=&DiscreteLogarithm::Pollard;
        qDebug()<<"listofalgorithm.h:current algorithm \"dPollard\"";
        return 3;
    }
    name_of_current_algorithm="";
}
