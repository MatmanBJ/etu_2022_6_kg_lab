QT += core gui

QT += widgets

CONFIG += c++11
TARGET = lab1
TEMPLATE = app


SOURCES += ./main.cpp \
./graphic/mainWindow.cpp ./graphic/drawField.cpp ./graphic/settingPanel.cpp \
./shapes/sPoint.cpp ./shapes/sLine.cpp ./shapes/sCircle.cpp \
./shapes/sOriginPlane.cpp \
./tools/matrix.cpp ./tools/sup.cpp

HEADERS  += ./include_graphic/mainWindow.h ./include_graphic/drawField.h ./include_graphic/settingPanel.h \
./include_graphic/matrix.h ./include_graphic/sup.h \
./include_shapes/allshapes.h