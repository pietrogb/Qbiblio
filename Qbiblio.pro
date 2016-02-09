#-------------------------------------------------
#
# Project created by QtCreator 2016-02-07T01:11:11
#
#-------------------------------------------------

QT += widgets
QT += xml
QT -= core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    Model/libraryitem.cpp \
    Model/libro.cpp \
    Model/cd.cpp \
    Model/dvd.cpp \
    Model/vhs.cpp \
    Model/film.cpp \
    Model/smartptr.cpp \
    main.cpp \
    View/mywidget.cpp


HEADERS += \
    Model/libraryitem.h \
    Model/libro.h \
    Model/cd.h \
    Model/dvd.h \
    Model/vhs.h \
    Model/film.h \
    Model/container.h \
    Model/smartptr.h \
    View/mywidget.h
