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
    ListModels/appsfuncproplistmodel.cpp \
    contextmenu.cpp \
    ListModels/virtuallistmodel.cpp \
    Forms/newfiledialog.cpp \
    Forms/addeditappearence.cpp \
    Forms/addeditappprop.cpp \
    Forms/addeditfunction.cpp

HEADERS  += mainwindow.h \
    luaparser.h \
    filelistmodel.h \
    loadfunction.h \
    appearence.h \
    ListModels/funcslistmodel.h \
    ListModels/appslistmodel.h \
    ListModels/appsfuncproplistmodel.h \
    contextmenu.h \
    ListModels/virtuallistmodel.h \
    Forms/newfiledialog.h \
    Forms/addeditappearence.h \
    Forms/addeditappprop.h \
    Forms/addeditfunction.h

FORMS    += mainwindow.ui \
    Forms/newfiledialog.ui \
    Forms/addeditappearence.ui \
    Forms/addeditappprop.ui \
    Forms/addeditfunction.ui
