# .pro file for your Qt project

QT       += core gui sql widgets
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += c++11
TARGET = ttt
TEMPLATE = app

# Sources
SOURCES += \
    agent.cpp \
    board.cpp \
    game.cpp \
    gamelogic.cpp \
    gamestate.cpp \
    humanplayer.cpp \
    login.cpp \
    main.cpp \
    startup.cpp \
    widget.cpp \
    gamehistory.c

# Headers
HEADERS += \
    agent.h \
    board.h \
    game.h \
    gamelogic.h \
    gamestate.h \
    humanplayer.h \
    login.h \
    player.h \
    startup.h \
    widget.h \
    gamehistory.h

# Forms
FORMS += \
    login.ui \
    startup.ui \
    widget.ui

# Compiler flags
QMAKE_CXXFLAGS += -std=c++17

# Standard library include path
INCLUDEPATH += C:/Path/To/Your/MinGW/include

# Linking standard library
LIBS += -lstdc++

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Additional files
DISTFILES += \
    .gitignore \
    ttt.pro.user
