#-------------------------------------------------
#
# Project created by QtCreator 2013-04-22T11:44:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = StrikerLoadViewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    luaparser.cpp \
    filelistmodel.cpp \
    loadfunction.cpp \
    appearence.cpp \
    ListModels/funcslistmodel.cpp \
    ListModels/appslistmodel.cpp \
    ListModels/appsfuncproplistmodel.cpp

HEADERS  += mainwindow.h \
    luaparser.h \
    filelistmodel.h \
    loadfunction.h \
    appearence.h \
    ListModels/funcslistmodel.h \
    ListModels/appslistmodel.h \
    ListModels/appsfuncproplistmodel.h

FORMS    += mainwindow.ui
