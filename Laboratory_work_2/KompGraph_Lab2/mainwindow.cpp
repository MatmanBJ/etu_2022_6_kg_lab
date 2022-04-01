#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"
#include <QAbstractScrollArea>


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  scene = new QGraphicsScene();
  ui->graphicsView->setScene(scene);

  ui->graphicsView->setContextMenuPolicy(Qt::CustomContextMenu);

  connect(ui->graphicsView, SIGNAL(customContextMenuRequested(QPoint)), this,

          SLOT(showContextMenu(QPoint)));

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::showContextMenu(const QPoint &pos) {

  QPoint globalPos = ui->graphicsView->mapToGlobal(pos);
  QPointF scenePos = ui->graphicsView->mapToScene(pos);

  QMenu menu;
  menu.addAction("Удалить", this, SLOT(on_action()));
 // menu.addAction("Пункт 2", this, SLOT(onAction2()));
  QAction *selectedItem = menu.exec(globalPos);

  if (selectedItem) {
   // QMessageBox::warning(this, "", QString::fromUtf8("Выбран %1").arg(selectedItem->text()));

    auto items = scene->items();
    for(auto item : items)
    {

        qDebug() << (item->scenePos()) <<  scenePos;
        if(abs(item->scenePos().x()-scenePos.x()) < 10  && abs(item->scenePos().y()-scenePos.y()) < 10  )
            scene->removeItem(item);
    }

  }
  else {
    QMessageBox::warning(this, "", QString::fromUtf8("Ничего не выбрано"));
    }

}

void MainWindow::on_action(){
   // scene->addLine(pos.x(),pos.y(),100,100);
}


void MainWindow::on_pushButton_clicked()
{
    QPoint pos;
    MoveItem *item = new MoveItem();        // Создаём графический элемента
    item->setPos(pos.x(),pos.y());
    scene->addItem(item);

}


void MainWindow::on_buildButton_clicked()
{

  QVector<QPoint> points;
  auto items = scene->items();

  for(int i=0;i < items.size()-1;i++){
      QLineF *line = new QLineF();

     QPointF globPoint1 = items[i]->scenePos().toPoint();
     points.push_back(globPoint1.toPoint());
     QPointF globPoint2 = items[i+1]->scenePos().toPoint();
     if(i+1 == items.size()-1)points.push_back(globPoint2.toPoint());
     QPointF p(5,5);
     line->setPoints(globPoint1+p,globPoint2+p);
      scene->addLine(*line);

  };


   // for(int i = 0; i<points.size() ;i++)qDebug()<< points[i];


  if(points.size()){
      QPoint pos;
      Bizye *B = new Bizye(points);
      B->setPos(pos.x(),pos.y());
      scene->addItem(B);
  }

}

void MainWindow::on_clearButton_clicked()
{
    auto items = scene->items();
    for(auto item : items)
    {
      scene->removeItem(item);
    }

}
