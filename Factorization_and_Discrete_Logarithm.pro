#-------------------------------------------------
#
# Project created by QtCreator 2014-10-27T08:58:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Factorization_and_Discrete_Logarithm
TEMPLATE = app
#CONFIG += console
CONFIG += c++11
#QMAKE_CXXFLAGS += -std=c++11
SOURCES += main.cpp\
        widget.cpp \
    algorithm.cpp \
    LongNumber/longint.cpp \
    LongNumber/longdouble.cpp\
    listofalgorithm.cpp \
    Algorithm/factorization.cpp \
    Algorithm/discrete_logarithm.cpp

HEADERS  += widget.h \
    algorithm.h \
    listofalgorithm.h \
    Algorithm/factorization.h \
    Algorithm/discrete_logarithm.h
    #LongNumber/longint.h \
    #LongNumber/longdouble.h
