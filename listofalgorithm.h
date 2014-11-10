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

class Factorization;
class DiscreteLogarithm;

class LongInt;
class ListofAlgorithm
{
    public:
        ListofAlgorithm();
        ~ListofAlgorithm();

        QString run_factorization(QString );
        QString run_discrete_logarithm(QString, QString, QString);
        QString getListofAlgorithm();
        int set(QString);
    private:
        QVector<int>::iterator iter;
        QTime timer;
        QString name_of_current_algorithm="";
        QVector<LongInt> (*current_algorithm_factorization)(LongInt)=NULL;
        LongInt (*current_algorithm_logarithm)(LongInt,LongInt,LongInt)=NULL;
};

#endif // LISTOFALGORITHM_H
