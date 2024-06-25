QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChislaFinder
TEMPLATE = app

SOURCES += main.cpp \
           chislawidget.cpp

HEADERS += chislawidget.h
