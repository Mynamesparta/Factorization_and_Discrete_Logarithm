#include "listofalgorithm.h"

ListofAlgorithm::ListofAlgorithm()
{
    //set("Fermat");
}
ListofAlgorithm::~ListofAlgorithm()
{

}

QString ListofAlgorithm::run(QString first)
{
    LongInt a(first);
    QString text;
    text="<h3>current algorithm:</h3> <h2>"+name_of_current_algorithm+"</h2>\n";
    timer.restart();
    //==================run=algorithm======
    QVector<LongInt>result((*current_algorithm)(a));
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

QString ListofAlgorithm::getListofAlgorithm()
{
    return "Fermat World_of_Test";
}

int ListofAlgorithm::set(QString name )
{
    name_of_current_algorithm=name;
    if(name=="Fermat")
    {
        current_algorithm=&Factorization::Fermat;
        qDebug()<<"listofalgorithm.h:current algorithm \"Fermat\"";
        return 1;
    }
    if(name=="World_of_Test")
    {
        current_algorithm=&Factorization::World_of_Test;
        qDebug()<<"listofalgorithm.h:current algorithm \"World_of_Test\"";
        return 1;
    }
    name_of_current_algorithm="";
}
