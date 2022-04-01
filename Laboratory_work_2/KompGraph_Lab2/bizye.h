#ifndef BIZYE_H
#define BIZYE_H

#include <QObject>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QPointF>
#include <QVector>

class Bizye :  public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Bizye(QObject *parent = nullptr);
        ~Bizye();
    Bizye(QVector<QPoint> vec);// возможно стоит добавить параметр родитель
    double factorial(int num);
    double powr(float num,int k);


signals:

private:
    QVector<QPointF> bizye_points;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void countBizyePoints(QVector<QPoint> vec);

    QPoint Bern(int t,int i,QVector<QPoint> points); //unused recurtion funkt.

};

#endif // BIZYE_H
