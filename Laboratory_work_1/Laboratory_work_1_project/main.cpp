// main.cpp
// This file is responsible main project

#include <QApplication>
#include <QIcon>

#include "./include_graphic/mainWindow.h"
#include "./include_graphic/sup.h"

// ---------- MAIN ----------

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);  
    
    MainWindow window;

    window.setWindowTitle("lab1");
    window.resize(1000, 750);
    //window.setWindowIcon(QIcon("./imgsrc/ico.png"));

    window.show();

    return app.exec();
}