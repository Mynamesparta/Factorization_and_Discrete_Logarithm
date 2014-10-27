#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),qre("[^0-9]")
{
    qmb.setFixedWidth(0);
    QStringList stringlist;//=algorithm.getListofAlgorithm().split(" ");
    qcbListOfAlgorithm=new QComboBox();
    qcbListOfAlgorithm->addItems(stringlist);
    qblToptoBotton=new QBoxLayout(QBoxLayout::TopToBottom);
    qblLefttoRight=new QBoxLayout(QBoxLayout::LeftToRight);
    qblToptoBotton->addWidget(qcbListOfAlgorithm);
    qblToptoBotton->addWidget(qlefirstnumber);
    qblToptoBotton->addWidget(qlesecondnumber);
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
}

Widget::~Widget()
{
}

void Widget::slot_FindtheValue()
{
    this->hide();
    qmb.information(this,qcbListOfAlgorithm->currentText(),
                             (qlefirstnumber->text(),qlesecondnumber->text()));
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
    //if(algorithm.set(name)==1)
    {
        qlesecondnumber->hide();
        qlesecondnumber->clear();
    }
    //else
    {
        qlesecondnumber->show();
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
