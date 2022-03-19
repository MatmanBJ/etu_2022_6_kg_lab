QT += core gui

QT += widgets

CONFIG += c++11
QMAKE_LFLAGS += -static -static-pie
TARGET = lab_1
TEMPLATE = app
RC_FILE = lab_1.rc

SOURCES += ./main.cpp \
./graphic/mainWindow.cpp ./graphic/drawField.cpp ./graphic/settingPanel.cpp \
./shapes/sPoint.cpp ./shapes/sLine.cpp ./shapes/sCircle.cpp \
./shapes/sOriginPlane.cpp

HEADERS  += ./include_graphic/mainWindow.h ./include_graphic/drawField.h ./include_graphic/settingPanel.h \
./include_shapes/allshapes.h