#-------------------------------------------------
#
# Project created by QtCreator 2014-10-25T12:06:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network
QT += concurrent

TARGET = Taho
TEMPLATE = app
INCLUDEPATH +=    myLibsQT
TRANSLATIONS =taho_fr.ts\
    taho_en.ts\
    taho_xx.ts

SOURCES += main.cpp\
        tahomainw.cpp \
    ctahoopt.cpp \
    myLibsQT/cpixmap.cpp \
    myLibsQT/cmapsrc.cpp \
    myLibsQT/cosmopt.cpp \
    myLibsQT/urldownload.cpp \
    cdokmz.cpp \
    ctahocopy.cpp \
    myLibsQT/Logfile.cpp \
    myLibsQT/cpath.cpp \
    myLibsQT/cgeorect.cpp \
    myLibsQT/cxmlfile.cpp \
    myLibsQT/cosm.cpp \
    myLibsQT/Vectmap.cpp \
    myLibsQT/cgeopoint.cpp

HEADERS  += tahomainw.h \
    ctahoopt.h \
    myLibsQT/cpixmap.h \
    myLibsQT/cmapsrc.h \
    myLibsQT/cosmopt.h \
    myLibsQT/urldownload.h \
    cdokmz.h \
    ctahocopy.h \
    myLibsQT/Logfile.h \
    myLibsQT/cpath.h \
    myLibsQT/cgeorect.h \
    myLibsQT/cxmlfile.h \
    myLibsQT/cosm.h \
    myLibsQT/Vectmap.h \
    myLibsQT/cgeopoint.h

FORMS    += tahomainw.ui \
    ctahoopt.ui \
    cdokmz.ui \
    ctahocopy.ui

RESOURCES += \
    taho.qrc
