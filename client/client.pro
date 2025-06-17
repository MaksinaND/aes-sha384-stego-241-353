QT += core gui network widgets

CONFIG += c++17 console
CONFIG -= app_bundle

TARGET = client

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    loginwindow.cpp \
    registerdialog.cpp \
    apiclient.cpp

HEADERS += \
    mainwindow.h \
    loginwindow.h \
    registerdialog.h \
    apiclient.h

FORMS += \
    mainwindow.ui \
    login.ui \
    dialog.ui





