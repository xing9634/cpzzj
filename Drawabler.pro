#-------------------------------------------------
#
# Project created by QtCreator 2018-04-25T16:28:40
#
#-------------------------------------------------

QT += core gui
QT += sql
QT += widgets


TARGET = Drawabler
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DLL
CONFIG += qt warn_on release

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    corekernel.cpp \
    sqlconnector.cpp \
    qmysqlquerymodel.cpp \
    realtableview.cpp

HEADERS += \
        mainwindow.h \
    corekernel.h \
    sqlconnector.h \
    qmysqlquerymodel.h \
    realtableview.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    style.qrc
