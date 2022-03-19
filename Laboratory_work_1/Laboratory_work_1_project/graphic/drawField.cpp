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

#include "../include_shapes/allshapes.h"
#include "../include_graphic/drawField.h"
#include "../include_graphic/sup.h"

// ---------- DrawField ----------

// constructor
DrawField::DrawField(QWidget *parent) : QWidget(parent)
{
    // creating all the new objects
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
    // destructing (deleting) all the objects
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
void DrawField::init(
    int circle_1_x, int circle_1_y, int r1, // circle 1 coodrinates (x/y center, semidiameter)
    int circle_2_x, int circle_2_y, int r2, // circle 2 coordinates (x/y center, semidiameter)
    int tangent_1_x_1, int tangent_1_y_1, int tangent_1_x_2, int tangent_1_y_2, // tangent 1 coordinates (x/y start, x/y end)
    int tangent_2_x_1, int tangent_2_y_1, int tangent_2_x_2, int tangent_2_y_2, // tangent 2 coordinates (x/y start, x/y end)
    int tangent_3_x_1, int tangent_3_y_1, int tangent_3_x_2, int tangent_3_y_2, // tangent 3 coordinates (x/y start, x/y end)
    int tangent_4_x_1, int tangent_4_y_1, int tangent_4_x_2, int tangent_4_y_2, // tangent 4 coordinates (x/y start, x/y end)
    sOriginPlane offset) // offset from left high corner
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
    
    circle_1 = new sCircle(circle_1_x, circle_1_y, r1, offset); // center of the circle and its semidiameter
    circle_2 = new sCircle(circle_2_x, circle_2_y, r2, offset); // center of the circle and its semidiameter
    //tangent_1 = new sLine(tangent_1_x_1, tangent_1_y_1, tangent_1_x_2, tangent_1_y_2, offset); // here 4
    tangent_2 = new sLine(tangent_2_x_1, tangent_2_y_1, tangent_2_x_2, tangent_2_y_2, offset); // from first border point to second
    tangent_3 = new sLine(tangent_3_x_1, tangent_3_y_1, tangent_3_x_2, tangent_3_y_2, offset); // from first border point to second
    //tangent_4 = new sLine(tangent_4_x_1, tangent_4_y_1, tangent_4_x_2, tangent_4_y_2, offset); // from first border point to second
    semidiameter_1 = new sLine(circle_1_x, circle_1_y, tangent_2_x_1, tangent_2_y_1, offset); // semidiameter from center to border point
    semidiameter_2 = new sLine(circle_1_x, circle_1_y, tangent_3_x_1, tangent_3_y_1, offset); // semidiameter from center to border point
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