#-------------------------------------------------
#
# Project created by QtCreator 2013-01-20T13:19:23
#
#-------------------------------------------------

QT       += core gui\
         += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QMemory_GUI
TEMPLATE = app

INCLUDEPATH += ../Memory_API/


SOURCES += main.cpp\
        mainwindow.cpp \
    ../Memory_API/src/second_turn.cpp \
    ../Memory_API/src/player.cpp \
    ../Memory_API/src/game_interface.cpp \
    ../Memory_API/src/first_turn.cpp \
    ../Memory_API/src/field_implementation.cpp \
    ../Memory_API/src/end_turn.cpp \
    ../Memory_API/src/card.cpp \
    ../Memory_API/src/view.cpp \
    memory_widget.cpp \
    qmemory_state.cpp \
    qmemory_first_turn.cpp \
    qmemory_second_turn.cpp \
    memory_card.cpp

HEADERS  += mainwindow.h \
    ../Memory_API/include/view_state.h \
    ../Memory_API/include/view.h \
    ../Memory_API/include/second_turn.h \
    ../Memory_API/include/player.h \
    ../Memory_API/include/memory_state.h \
    ../Memory_API/include/game_interface.h \
    ../Memory_API/include/first_turn.h \
    ../Memory_API/include/field_implementation.h \
    ../Memory_API/include/end_turn.h \
    ../Memory_API/include/card.h \
    memory_widget.h \
    qmemory_state.h \
    qmemory_first_turn.h \
    qmemory_second_turn.h \
    memory_card.h

FORMS    += mainwindow.ui

