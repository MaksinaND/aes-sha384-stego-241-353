QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += core network

# Добавляем модуль для работы с изображениями
QT += gui

SOURCES += \
    aes.cpp \
    aescipher.cpp \
    chordmethod.cpp \
    loginwindow.cpp \
    main_tabs.cpp \
    mainwindow_tabs.cpp \
    myclient.cpp \
    registerdialog.cpp \
    sha384.cpp \
    sha384hasher.cpp \
    steganography.cpp

HEADERS += \
    aes.h \
    aescipher.h \
    chordmethod.h \
    loginwindow.h \
    mainwindow_tabs.h \
    myclient.h \
    registerdialog.h \
    sha384.h \
    sha384hasher.h \
    steganography.h

FORMS += \
    dialog.ui \
    login.ui \
    mainwindow_tabs.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

