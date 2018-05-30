QT += core
QT -= gui

CONFIG += c++11

TARGET = base6
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


INCLUDEPATH += \
         $$PWD/3rdparty \
        $$PWD/3rdparty/cppcodec


SOURCES += main.cpp \
    base64.cpp
