// drawField.cpp
// This file is responsible for drawing lines and circles

// Line 1 -- up parallel (outside)
// Line 2 -- up crossing (inside)
// Line 3 -- down crossing (inside)
// Line 4 -- down parallel (outside)

#include <QWidget>
#include <QPainter>
#include <cmath>
#include <iostream>

#include "../include_graphic/drawField.h"
#include "../shapes/shapes"
#include "../include_graphic/sup.h"

// ---------- DrawField ----------

// constructor
DrawField::DrawField(QWidget *parent) : QWidget(parent)
{
    o1 = NULL;
    o2 = NULL;
    //cas1 = NULL; // here 1
    cas2 = NULL;
    cas3 = NULL;
    //cas4 = NULL;

    resize(W, H);
    this->setStyleSheet("background-color: rgb(200,200,200); margin:0px; border:1px solid rgb(0, 0, 0); ");
}

// ---------- ~DrawField ----------

// destructor
DrawField::~DrawField()
{
    if(o1 != NULL)
        delete o1;
    if(o2 != NULL)
        delete o2;
    //if(cas1 != NULL) // here 2
        //delete cas1; // here 2
    if(cas2 != NULL)
        delete cas2;
    if(cas3 != NULL)
        delete cas3;
    //if(cas4 != NULL)
        //delete cas4;
}

// ---------- paintEvent ----------

// drawing all of the composition
void DrawField::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter qp(this);
    drawLines(&qp);
}

// ---------- init ----------

// initializing cordinates, that we counted
void DrawField::init(int x01, int y01, int r1, 
              int x02, int y02, int r2,
              int l1x1, int l1y1, int l1x2, int l1y2,
              int l2x1, int l2y1, int l2x2, int l2y2,
              int l3x1, int l3y1, int l3x2, int l3y2,
              int l4x1, int l4y1, int l4x2, int l4y2,
              sOriginPlane cb)
{
    if(o1 != NULL)
        delete o1;
    if(o2 != NULL)
        delete o2;
    //if(cas1 != NULL) // here 3
        //delete cas1; // here 3
    if(cas2 != NULL)
        delete cas2;
    if(cas3 != NULL)
        delete cas3;
    //if(cas4 != NULL)
        //delete cas4;
    
    o1 = new sCircle(x01, y01, r1, cb);
    o2 = new sCircle(x02, y02, r2, cb);
    //cas1 = new sLine(l1x1, l1y1, l1x2, l1y2, cb); // here 4
    cas2 = new sLine(l2x1, l2y1, l2x2, l2y2, cb);
    cas3 = new sLine(l3x1, l3y1, l3x2, l3y2, cb);
    //cas4 = new sLine(l4x1, l4y1, l4x2, l4y2, cb);
}

// ---------- drawLines ----------

// drawing lines, that we have
void DrawField::drawLines(QPainter *qp)
{
    QColor colo(0, 0, 0);
    QPen pen(colo);
    qp->setPen(pen);

    if(
        o1 != NULL &&
        o2 != NULL &&
        //cas1 != NULL && // here 5
        cas2 != NULL &&
        cas3 != NULL// &&
        //cas4 != NULL
    )
    {
        o1->sdraw(*qp);
        o2->sdraw(*qp);
        //cas1->sdraw(*qp); // here 6
        cas2->sdraw(*qp);
        cas3->sdraw(*qp);
        //cas4->sdraw(*qp);
    }
}