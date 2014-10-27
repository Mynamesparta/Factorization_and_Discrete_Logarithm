#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QComboBox>
#include <QTimerEvent>
#include <QList>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QRegExp>
#include <QMessageBox>
#include "listofalgorithm.h"

class ListofAlgorithm;

class Widget : public QWidget
{
    Q_OBJECT
private:
    QRegExp qre;
    ListofAlgorithm algorithm;
    QMessageBox qmb;
    QBoxLayout* qblToptoBotton;
    QBoxLayout* qblLefttoRight;
    QComboBox* qcbListOfAlgorithm;
    QLineEdit* qlefirstnumber=new QLineEdit();
    QLineEdit* qlesecondnumber=new QLineEdit();
    QPushButton* qpbFindtheValue=new QPushButton("&Знайти значення..");
public:
    Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void slot_FindtheValue();
    void slot_TextEdit(QString text);
    void slot_ChoseAlgorithm(const QString &);
    void slot_Show_Number(int);
};

#endif // WIDGET_H
