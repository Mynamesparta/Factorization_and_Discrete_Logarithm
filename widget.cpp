#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),qre("[^0-9]")
{
    qmb.setFixedWidth(0);
    QStringList stringlist=algorithm.getListofAlgorithm().split(" ");
    qcbListOfAlgorithm=new QComboBox();
    qcbListOfAlgorithm->addItems(stringlist);
    qblToptoBotton=new QBoxLayout(QBoxLayout::TopToBottom);
    qblLefttoRight=new QBoxLayout(QBoxLayout::LeftToRight);
    qblToptoBotton->addWidget(qcbListOfAlgorithm);
    qblToptoBotton->addWidget(qlfirstnumber);
    qblToptoBotton->addWidget(qlefirstnumber);
    qblToptoBotton->addWidget(qlsecondnumber);
    qblToptoBotton->addWidget(qlesecondnumber);
    qblToptoBotton->addWidget(qlthirdnumber);
    qblToptoBotton->addWidget(qlethirdnumber);
    //-----
    qblLefttoRight->addStretch(2);
    qblLefttoRight->addWidget(qpbFindtheValue,1);
    qblLefttoRight->addStretch(2);
    //-----
    qblToptoBotton->addLayout(qblLefttoRight);
    this->setLayout(qblToptoBotton);
    this->setMinimumSize(600,400);
    //===================connect===========================
    connect(qlefirstnumber,SIGNAL(textChanged(QString)),
            this,SLOT(slot_TextEdit(QString)));
    connect(qlesecondnumber,SIGNAL(textChanged(QString)),
            this,SLOT(slot_TextEdit(QString)));
    connect(qpbFindtheValue,SIGNAL(clicked()),
            this,SLOT(slot_FindtheValue()));
    connect(qcbListOfAlgorithm,SIGNAL(activated(QString)),
            this,SLOT(slot_ChoseAlgorithm(QString)));
    //=====================================================
    slot_ChoseAlgorithm("Fermat");
    qDebug()<<"widget.cpp List of algorithm:"<<algorithm.getListofAlgorithm();
}

Widget::~Widget()
{
    /*/
    delete  qlefirstnumber;
    delete  qlesecondnumber;
    delete  qlethirdnumber;
    delete  qlfirstnumber;
    delete  qlsecondnumber;
    delete  qlthirdnumber;
    /*/
}

void Widget::slot_FindtheValue()
{
    this->hide();
    if(qlfirstnumber->isHidden())
        qmb.information(this,qcbListOfAlgorithm->currentText(),
                             algorithm.run_factorization(qlefirstnumber->text()));
    else
        qmb.information(this,qcbListOfAlgorithm->currentText(),
                             algorithm.run_discrete_logarithm(qlefirstnumber->text(),qlesecondnumber->text(),qlethirdnumber->text()));
    this->show();
}

void Widget::slot_TextEdit(QString text)
{
    QLineEdit* qle=((QLineEdit*)sender());
    if(text.contains(qre)||( text=="0"))
    {
        qle->backspace();
    }
}


void Widget::slot_ChoseAlgorithm(const QString & name)
{
    switch(algorithm.set(name))
    {
    case 1:
        qlesecondnumber->hide();
        qlesecondnumber->clear();
        qlethirdnumber->hide();
        qlethirdnumber->clear();

        qlfirstnumber->hide();
        qlsecondnumber->hide();
        qlthirdnumber->hide();
        break;
    case 2:
        qlesecondnumber->show();

        qlfirstnumber->hide();
        qlsecondnumber->hide();
        qlthirdnumber->hide();
        break;
    case 3:
        qlesecondnumber->show();
        qlethirdnumber->show();
        qlfirstnumber->show();
        qlsecondnumber->show();
        qlthirdnumber->show();
        break;
    }
}

void Widget::slot_Show_Number(int i)
{
    if(i==1)
    {
        qlesecondnumber->hide();
        qlesecondnumber->clear();
    }
    if(i==2)
    {
        qlesecondnumber->show();
    }
}
