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

}

QString ListofAlgorithm::getListofAlgorithm()
{
    return "Fermat";
}

int ListofAlgorithm::set(QString name )
{
    if(name=="Fermat")
    {
        current_algorithm=&Factorization::Fermat;
        qDebug()<<"listofalgorithm.h:current algorithm \"Fermat\"";
        return 1;
    }
}
