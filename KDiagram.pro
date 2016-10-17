#-------------------------------------------------
#
# Project created by QtCreator 2016-10-14T09:37:37
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KDiagram
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    Download.cpp \
    DataModel.cpp

HEADERS  += widget.h \
    Download.h \
    DataModel.h

FORMS    += widget.ui
