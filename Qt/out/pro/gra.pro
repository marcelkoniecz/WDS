######################################################################
# Automatically generated by qmake (3.1) Fri Jun 3 14:42:44 2022
######################################################################

OBJECTS_DIR=./out/obj
INCLUDEPATH=inc
INCLUDEPATH+=ui/inc
INCLUDEPATH+=.inc
INCLUDEPATH+=./res/inc
INCLUDEPATH+=./ui/inc
RCC_DIR=./out/rcc
UI_DIR=./out/uic
QMAKE_CXXFLAGS+=-g
MOC_DIR=./out/moc
QT+=widgets
QT+=serialport
QT+=gui
LIBS+=-lpthread
QT+=core
QT+=charts
TRANSLATIONS=gra_pl.ts
TEMPLATE = app
TARGET = gra

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += ../../inc/dialogs.hpp \
           ../../inc/gameParameters.hpp \
           ../../inc/gameSettings.hpp \
           ../../inc/gameStatistics.hpp \
           ../../inc/gameWidget.hpp \
           ../../inc/gameWindow.hpp \
           ../../inc/mainWidget.hpp \
           ../../inc/sideWidget.hpp \
           ../../inc/uartParam.hpp
FORMS += ../../ui/aplicationmainwindow.ui \
         ../../ui/conDialog.ui \
         ../../ui/disDialog.ui \
         ../../ui/endGameDialog.ui \
         ../../ui/endGameDialog2.ui \
         ../../ui/gameStatistics.ui \
         ../../ui/gameWidget.ui \
         ../../ui/gameWidgetv2.ui \
         ../../ui/gameWindow.ui \
         ../../ui/settDialog.ui \
         ../../ui/settingsDialog.ui \
         ../../ui/sidePanelWidget.ui \
         ../../ui/sideWidget.ui
SOURCES += ../../src/dialogs.cpp \
           ../../src/gameStatistics.cpp \
           ../../src/gameWidget.cpp \
           ../../src/gameWindow.cpp \
           ../../src/main.cpp \
           ../../src/mainWidget.cpp \
           ../../src/sideWidget.cpp
RESOURCES += ../../res/zasoby.qrc
