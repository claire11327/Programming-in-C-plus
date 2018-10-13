#-------------------------------------------------
#
# Project created by QtCreator 2017-04-20T19:17:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bullet.cpp \
    character.cpp \
    check.cpp

HEADERS  += mainwindow.h \
    bullet.h \
    character.h \
    check.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
