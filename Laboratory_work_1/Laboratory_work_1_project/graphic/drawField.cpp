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
    circle_1 = NULL;
    circle_2 = NULL;
    //tangent_1 = NULL; // here 1
    tangent_2 = NULL;
    tangent_3 = NULL;
    //tangent_4 = NULL;
    semidiameter_1 = NULL;
    semidiameter_2 = NULL;

    // resizing and setting background
    //resize(W, H);
    //this->setStyleSheet("background-color: rgb(200,200,200); margin:0px; border:1px solid rgb(0, 0, 0); "); // grey
    resize(W, H);
    this->setStyleSheet("background-color: rgb(255,255,255); margin:0px; border:1px solid rgb(0, 0, 0); "); // white
}

// ---------- ~DrawField ----------

// destructor
DrawField::~DrawField()
{
    if (circle_1 != NULL)
    {
        delete circle_1;
    }
    if (circle_2 != NULL)
    {
        delete circle_2;
    }
    //if (tangent_1 != NULL) // here 2
        //delete tangent_1; // here 2
    if (tangent_2 != NULL)
    {
        delete tangent_2;
    }
    if (tangent_3 != NULL)
    {
        delete tangent_3;
    }
    //if (tangent_4 != NULL)
        //delete tangent_4;
    if (semidiameter_1 != NULL)
    {
        delete semidiameter_1;
    }
    if (semidiameter_2 != NULL)
    {
        delete semidiameter_2;
    }
}

// ---------- paintEvent ----------

// drawing all of the composition
void DrawField::paintEvent(QPaintEvent *local_event)
{
    Q_UNUSED(local_event);
    QPainter local_qpainter(this); // creating QPainter
    drawLines(&local_qpainter); // drawing lines with QPainter
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
    // cleaning before making something -- we can input new parameters
    if (circle_1 != NULL)
    {
        delete circle_1;
    }
    if (circle_2 != NULL)
    {
        delete circle_2;
    }
    //if (tangent_1 != NULL) // here 3
        //delete tangent_1; // here 3
    if (tangent_2 != NULL)
    {
        delete tangent_2;
    }
    if (tangent_3 != NULL)
    {
        delete tangent_3;
    }
    //if (tangent_4 != NULL)
        //delete tangent_4;
    if (semidiameter_1 != NULL)
    {
        delete semidiameter_1;
    }
    if (semidiameter_2 != NULL)
    {
        delete semidiameter_2;
    }
    
    circle_1 = new sCircle(x01, y01, r1, cb); // center of the circle and its semidiameter
    circle_2 = new sCircle(x02, y02, r2, cb); // center of the circle and its semidiameter
    //tangent_1 = new sLine(l1x1, l1y1, l1x2, l1y2, cb); // here 4
    tangent_2 = new sLine(l2x1, l2y1, l2x2, l2y2, cb); // from first border point to second
    tangent_3 = new sLine(l3x1, l3y1, l3x2, l3y2, cb); // from first border point to second
    //tangent_4 = new sLine(l4x1, l4y1, l4x2, l4y2, cb); // from first border point to second
    semidiameter_1 = new sLine(x01, y01, l2x1, l2y1, cb); // semidiameter from center to border point
    semidiameter_2 = new sLine(x01, y01, l3x1, l3y1, cb); // semidiameter from center to border point
}

// ---------- drawLines ----------

// drawing lines, that we have
void DrawField::drawLines(QPainter *local_qpainter)
{
    if(circle_1 != NULL && circle_2 != NULL && /*tangent_1 != NULL && // here 5*/ tangent_2 != NULL && tangent_3 != NULL/* && tangent_4 != NULL*/)
    {
        QColor color_1(0, 0, 255); // blue color setting for circles
        QPen pen_1(color_1); // pen setting
        local_qpainter->setPen(pen_1); // pen setting for special object

        circle_1->sdraw(*local_qpainter);
        circle_2->sdraw(*local_qpainter);

        QColor color_2(255, 0, 0); // red color setting for lines
        QPen pen_2(color_2); // pen setting
        local_qpainter->setPen(pen_2); // pen setting for special object

        //tangent_1->sdraw(*qp); // here 6
        tangent_2->sdraw(*local_qpainter);
        tangent_3->sdraw(*local_qpainter);
        //tangent_4->sdraw(*qp);

        QColor color_3(0, 0, 0); // black color setting for semidiameter
        QPen pen_3(color_3); // pen setting
        local_qpainter->setPen(pen_3); // pen setting for special object

        semidiameter_1->sdraw(*local_qpainter);
        semidiameter_2->sdraw(*local_qpainter);
    }
}