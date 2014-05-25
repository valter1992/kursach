#-------------------------------------------------
#
# Project created by QtCreator 2014-05-18T15:01:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kursovik
TEMPLATE = app
CONFIG += qwt
CONFIG += QwtPlot

INCLUDEPATH += /usr/local/qwt-6.1.0/include/
LIBS += /usr/local/qwt-6.1.0/lib/libqwt.so.6

SOURCES += main.cpp\
        mainwindow.cpp \
    work.cpp \
    graph.cpp

HEADERS  += mainwindow.h \
    work.h \
    structures.h \
    graph.h

FORMS    += mainwindow.ui \
    work.ui \
    graph.ui
