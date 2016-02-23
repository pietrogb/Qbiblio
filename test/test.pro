TEMPLATE = app
#TARGET = Qbiblio
INCLUDEPATH += . View Model
QT += widgets
QT += xml

HEADERS += ../Model/cd.h \
           ../Model/container.h \
           ../Model/dvd.h \
           ../Model/film.h \
           ../Model/libraryitem.h \
           ../Model/libro.h \
           ../Model/smartptr.h \
           ../Model/biblio.h \
           ../Model/vhs.h
SOURCES += main.cpp \
           ../Model/cd.cpp \
           ../Model/dvd.cpp \
           ../Model/film.cpp \
           ../Model/libraryitem.cpp \
           ../Model/libro.cpp \
           ../Model/smartptr.cpp \
           ../Model/biblio.cpp \
           ../Model/vhs.cpp
