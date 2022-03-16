// mainWindow.h
// This file is a header for "mainWindow.cpp" file

#ifndef MAINWINDOW_H

#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QMainWindow>

#include "../include/settingPanel.h"
#include "../include/drawField.h"

class MainWindow : public QWidget
{
    private:
    SettingPanel *settingPanel;
    DrawField *drawField;

    public:
    MainWindow(QWidget *parent = 0);

    SettingPanel* getSettingPanel();
    DrawField* getDrawField();
};

#endif // MAINWINDOW_H