QT += testlib
QT += widgets
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=   \
tst_everything.cpp \
../agent.cpp \
../board.cpp \
../game.cpp \
../gamelogic.cpp \
../gamestate.cpp \
../humanplayer.cpp \
../login.cpp \
../startup.cpp \
../widget.cpp \

FORMS += \
    ../widget.ui \
    ../login.ui \
    ../startup.ui \

HEADERS += \
    ../agent.h \
    ../board.h \
    ../game.h \
    ../gamelogic.h \
    ../gamestate.h \
    ../humanplayer.h \
    ../login.h \
    ../player.h \
    ../startup.h \
    ../widget.h \
