#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QMenu>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QVector>
#include <QPushButton>
#include "moveitem.h"
#include <bizye.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QPainter painter;
    QGraphicsScene *scene;

public slots:
    void showContextMenu(const QPoint &pos);
    void on_action();
    void on_pushButton_clicked();
    void on_buildButton_clicked();
    void on_clearButton_clicked();

};
#endif // MAINWINDOW_H
