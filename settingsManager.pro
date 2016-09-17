#-------------------------------------------------
#
# Project created by QtCreator 2016-09-16T19:02:46
#
#-------------------------------------------------

QT       -= gui

TARGET = settingsManager
TEMPLATE = lib
CONFIG += staticlib

DEFINES += SETTINGSMANAGER_LIBRARY

SOURCES += settingsmanager.cpp

HEADERS += settingsmanager.h\
        settingsmanager_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
