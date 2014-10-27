#-------------------------------------------------
#
# Project created by QtCreator 2014-10-27T08:58:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Factorization_and_Discrete_Logarithm
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp \
    algorithm.cpp \
    LongNumber/longint.cpp \
    LongNumber/longdouble.cpp\
    factorization_and_discrete_logarithm.cpp \
    listofalgorithm.cpp

HEADERS  += widget.h \
    algorithm.h \
    factorization_and_discrete_logarithm.h \
    listofalgorithm.h
    #LongNumber/longint.h \
    #LongNumber/longdouble.h
