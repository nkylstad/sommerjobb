#-------------------------------------------------
#
# Project created by QtCreator 2013-06-25T13:31:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DolfinGui
TEMPLATE = app


SOURCES += main.cpp\
    PlotWidget.cpp \
    DolfinGui.cpp \
    Plotter.cpp \
    BoundaryMeshFunction.cpp \
    CoordLabel.cpp \
    CSGGeometryFunction.cpp

HEADERS  += \
    DolfinGui.h \
    PlotWidget.h \
    Plotter.h \
    BoundaryMeshFunction.h \
    CoordLabel.h \
    CSGGeometryFunction.h

FORMS    += dolfingui.ui

RESOURCES += DolfinGui.qrc

OTHER_FILES += \
    CMakeLists.txt
