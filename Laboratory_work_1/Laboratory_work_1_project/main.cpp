// main.cpp
// This file is responsible main project

#include <QApplication>
#include <QIcon>

#include "./include_graphic/mainWindow.h"

// ---------- MAIN ----------

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);  
    
    MainWindow window;

    window.setWindowTitle("Laboratory work 1");
    window.resize(1000, 500);
    //window.setWindowIcon(QIcon("./icon/icon.ico"));

    window.show();

    return app.exec();
}