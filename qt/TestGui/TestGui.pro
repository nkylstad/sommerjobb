#-------------------------------------------------
#
# Project created by QtCreator 2013-06-20T11:09:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestGui
TEMPLATE = app


SOURCES += main.cpp\
        guiwindow.cpp \
    Plotter.cpp

HEADERS  += guiwindow.h \
    Plotter.h

FORMS    += guiwindow.ui

RESOURCES += guiwindow.qrc

