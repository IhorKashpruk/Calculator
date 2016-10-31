QT += core
QT -= gui

CONFIG += c++11
#QMAKE_CXXFLAGS_DEBUG -= -O1
#QMAKE_CXXFLAGS_DEBUG -= -O3
#QMAKE_CXXFLAGS_DEBUG *= -O2

TARGET = untitled5Console
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    calculator.cpp \
    expression.cpp \
    number.cpp \
    operation.cpp

HEADERS += \
    calculator.h \
    expression.h \
    number.h \
    operation.h
