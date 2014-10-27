#ifndef LISTOFALGORITHM_H
#define LISTOFALGORITHM_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QVector>
#include <QTime>

#include "algorithm.h"
#include "Algorithm/discrete_logarithm.h"
#include "Algorithm/factorization.h"

class Algorithm;
class Factorization;
class DiscreteLogarithm;

class LongInt;
class ListofAlgorithm
{
    public:
        ListofAlgorithm();
        ~ListofAlgorithm();

        QString run(QString first);
        QString getListofAlgorithm();
        int set(QString);
    private:
        QVector<int>::iterator iter;
        QTime timer;
        QString name_of_current_algorithm="";
        QVector<LongInt> (*current_algorithm)(LongInt)=NULL;
};

#endif // LISTOFALGORITHM_H
