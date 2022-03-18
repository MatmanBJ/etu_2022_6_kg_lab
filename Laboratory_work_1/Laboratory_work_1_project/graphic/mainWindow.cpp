// mainWindow.cpp
// This file is responsible for constructing main window

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QMainWindow>
#include <QGridLayout>

#include "../include_graphic/mainWindow.h"
#include "../include_graphic/settingPanel.h"
#include "../include_graphic/drawField.h"

// ---------- MainWindow ----------

// constructor
MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    //https://stackoverflow.com/questions/25450598/qlayout-attempting-to-add-qlayout-to-qwidget-which-already-has-a-layout
    QGridLayout *grid = new QGridLayout(this);

    settingPanel = new SettingPanel(this);
    drawField = new DrawField(this);

    grid->addWidget(settingPanel, 0, 0);
    grid->addWidget(drawField, 0, 1);

    grid->setColumnStretch(1, 100);

    setLayout(grid);
}

// ---------- getSettingPanel ----------

// returning (getting) the current setting panel pointer
SettingPanel* MainWindow::getSettingPanel()
{
    return settingPanel;
}

// ---------- getDrawField ----------

// returning (getting) the current draw field pointer
DrawField* MainWindow::getDrawField()
{
    return drawField;
}