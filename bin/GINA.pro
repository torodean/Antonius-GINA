#==========================================================================
# GINA (Generations of Implanted Nuclear Atrophy)
# Michigan State University - National Superconducting Cylotron Laboratory
# File: GINA.pro
# Created By: Antonius Torode
# File Created: June 22, 2017
# Purpose: This is the Qt project file for the GINA program.
#==========================================================================

#-------------------------------------------------
#
# Project created by QtCreator 2017-06-22T13:16:16
#
#-------------------------------------------------

QT += core gui \
        charts \
        core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GINA
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    gina.cpp \
    ginagraph.cpp \
    ginaelements.cpp \
    ginafit.cpp

HEADERS += \
    gina.h \
    ginagraph.h \
    ginaelements.h \
    ginafit.h

FORMS += \
    gina.ui

#target.path = $$[QT_INSTALL_EXAMPLES]/charts/chartthemes
#INSTALLS += target
