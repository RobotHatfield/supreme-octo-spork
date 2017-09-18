QT += network

include (network.pri)

HEADERS += \
    $$PWD/servercore.h \
    $$PWD/serverservice.h

SOURCES += \
    $$PWD/servercore.cpp \
    $$PWD/serverservice.cpp
