#-------------------------------------------------
#
# Project created by QtCreator 2019-06-03T22:53:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DungeonCrawler
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        ProcessObjects/column.cpp \
        ProcessObjects/database.cpp \
        ProcessObjects/processmodel.cpp \
        ProcessObjects/table.cpp \
        ProcessObjects/tinyxml2.cpp \
        ProcessObjects/xmlparser.cpp \
        database.cpp \
        main.cpp \
        mainwindow.cpp \
        processmodel.cpp \
        table.cpp \
        tinyxml2.cpp \
        xmlparser.cpp

HEADERS += \
        ProcessObjects/column.h \
        ProcessObjects/database.h \
        ProcessObjects/processmodel.h \
        ProcessObjects/table.h \
        ProcessObjects/tinyxml2.h \
        ProcessObjects/vxmlparser.h \
        ProcessObjects/xmlparser.h \
        database.h \
        mainwindow.h \
        processmodel.h \
        table.h \
        tinyxml2.h \
        vxmlparser.h \
        xmlparser.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
