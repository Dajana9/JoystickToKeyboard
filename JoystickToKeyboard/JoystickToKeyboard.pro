#-------------------------------------------------
#
# Project created by QtCreator 2018-03-07T12:45:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = joystickToKeyboard
TEMPLATE = app

INCLUDEPATH += /usr/include/SDL2/
INCLUDEPATH += /dev/uinput
INCLUDEPATH +=/home/uinputgroup
LIBS += -lSDL2

SOURCES += main.cpp\
        mainwindow.cpp \
    joystickcontrols.cpp \
    keyboard.cpp

HEADERS  += mainwindow.h \
    joystickcontrols.h \
    keyboard.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=gnu++14
