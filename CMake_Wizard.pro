#-------------------------------------------------
#
# Project created by QtCreator 2021-02-14T19:08:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CMake_Wizard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cmakelists.cpp

HEADERS  += mainwindow.h \
    cmakelists.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
