#-------------------------------------------------
#
# Project created by QtCreator 2016-09-26T14:36:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AED1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    palabra.cpp \
    listaenlazada.cpp \
    nodolista.cpp \
    extras.cpp \
    arbolbinario.cpp

HEADERS  += mainwindow.h \
    palabra.h \
    listaenlazada.h \
    nodolista.h \
    extras.h \
    arbolbinario.h \
    nodoab.h

FORMS    += mainwindow.ui

CONFIG += c++11
