QT += core network gui widgets

CONFIG += c++17 console
CONFIG -= app_bundle

TARGET = server

SOURCES += \
    main.cpp \
    apiserver.cpp \
    aes.cpp \
    steganography.cpp \
    sha384.cpp \
    chordmethod.cpp

HEADERS += \
    apiserver.h \
    aes.h \
    steganography.h \
    sha384.h \
    chordmethod.h



SOURCES += databasemanager.cpp



QT += sql


