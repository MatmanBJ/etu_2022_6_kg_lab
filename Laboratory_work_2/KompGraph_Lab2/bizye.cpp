#include "bizye.h"


//================C O U N T I N G=============
double Bizye::factorial(int num){

        int f;
        if (num == 0)
            f = 1;
        else
            f = num * factorial(num - 1);
        return f;
}

double Bizye::powr(float num, int k)
{    //only posutuve powers
    if(num != 0 && k!=1 ){
      if(k == 0)num = 1;
      else
         while(k>1){
            num *=num;
            k-=1;
        };
    }
    return num;
}


QPoint Bizye::Bern(int t,int i,QVector<QPoint> points){
    QPoint B;
        if(i == 0)
            B = QPoint(points[i].x(),points[i].y());
        else
            if(i==1)B = QPoint((1-t)*Bern(t,i-1,points).x(), (1-t)*Bern(t,i-1,points).y());
            else
                B = QPoint((1-t)*Bern(t,i-1,points).x() + t*Bern(t,i,points).x() , (1-t)*Bern(t,i-1,points).y() + t*Bern(t,i,points).y());;
        return B;
}

void Bizye::countBizyePoints(QVector<QPoint> points){

    float t = 1.0f;
    double x,y;
    int N = points.size() - 1;
   // qDebug()<< "privious points start";
   // for(int z = 0; z<points.size() ;z++)qDebug()<< points[z];
   // qDebug()<<  points.size() << "privious points end"  ;

    while(!(t < -0.0f)){
        x = 0;
        y = 0;
        double bernPoly = 0;
        for(int k = N; k>=0; --k){

            double C = ((double)factorial(N)/(double)(factorial(k)*factorial(N-k)));
            double p_t = powr(t,k);
            double p_mt = powr((1.0-t),N-k);
            bernPoly = C * p_t * p_mt;

            if(t==1){
                x = points[N].x();
                y = points[N].y();
            }
            else if(t==0){
                x = points[0].x();
                y = points[0].y();
            }
            else{
             x += points[k].x() * bernPoly;
             y += points[k].y() * bernPoly;
            };

    // qDebug()<< "t"<<t <<"koef" <<C << "(t^n)"<<p_t << "(1-t)"<<p_mt << "poly"<< bernPoly << "slogaemoe" << QPoint(points[k].x() * bernPoly,points[k].y() * bernPoly);
        }
        qDebug() << QPointF(x,y) ;
        bizye_points.push_back(QPointF(x+5,y+5));
        t-=0.10f;
        if(t>0.098f && t<0.1f) t = 0.1f;//нюансы си
    }
}

//===================================

Bizye::Bizye(QObject *parent) : QObject(parent),QGraphicsItem()
{

}

Bizye::~Bizye(){ }

Bizye::Bizye(QVector<QPoint> vec):QGraphicsItem()
{

    countBizyePoints(vec);
}


QRectF Bizye::boundingRect() const
{
    return QRectF (0,0,500,500);
}


void Bizye::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::red);
    painter->setBrush(Qt::red);

     for(int i=0;i < bizye_points.size()-1;i++){
         painter->drawLine(QLineF(bizye_points[i],bizye_points[i+1]));
     }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
