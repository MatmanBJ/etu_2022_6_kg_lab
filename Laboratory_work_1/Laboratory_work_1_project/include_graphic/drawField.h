// drawField.h
// This file is a header for "drawField.cpp" file

#ifndef DRAWFIELD_H

#define DRAWFIELD_H

#include <QWidget>

#include "../include_shapes/allshapes.h"

// https://ravesli.com/urok-12-risovanie-v-qt5/
// http://ingraf.ru/axonometry/detail49.htm

// ---------- DrawField ----------

class DrawField : public QWidget
{
private:
    const unsigned W = 300; // 300 basic
    const unsigned H = 350; // 350 basic
    sCircle *circle_1; // circle 1
    sCircle *circle_2; // circle 2
    sLine *tangent_1; // tangent line 1
    sLine *tangent_2; // tangent line 2
    sLine *tangent_3; // tangent line 3
    sLine *tangent_4; // tangent line 4
    sLine *semidiameter_1; // semidiameter (rus. radius) 1
    sLine *semidiameter_2; // semidiameter (rus. radius) 1

public:
    DrawField(QWidget *parent = 0); // constructor
    ~DrawField(); // destructor
    void init(
        int circle_1_x, int circle_1_y, int r1, // circle 1 coodrinates (x/y center, semidiameter)
        int circle_2_x, int circle_2_y, int r2, // circle 2 coordinates (x/y center, semidiameter)
        int tangent_1_x_1, int tangent_1_y_1, int tangent_1_x_2, int tangent_1_y_2, // tangent 1 coordinates (x/y start, x/y end)
        int tangent_2_x_1, int tangent_2_y_1, int tangent_2_x_2, int tangent_2_y_2, // tangent 2 coordinates (x/y start, x/y end)
        int tangent_3_x_1, int tangent_3_y_1, int tangent_3_x_2, int tangent_3_y_2, // tangent 3 coordinates (x/y start, x/y end)
        int tangent_4_x_1, int tangent_4_y_1, int tangent_4_x_2, int tangent_4_y_2, // tangent 4 coordinates (x/y start, x/y end)
        sOriginPlane offset); // offset from left high corner
    
protected:
    void paintEvent(QPaintEvent *local_event); // draw event with local event
    void drawLines(QPainter *local_qpainter); // draw lines with local painter
};

#endif // DRAWFIELD_H