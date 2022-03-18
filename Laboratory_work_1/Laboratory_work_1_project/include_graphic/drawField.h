// drawField.h
// This file is a header for "drawField.cpp" file

#ifndef DRAWFIELD_H

#define DRAWFIELD_H

#include <QWidget>

#include "../shapes/shapes"

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
    void init(int x01, int y01, int r1, 
              int x02, int y02, int r2,
              int l1x1, int l1y1, int l1x2, int l1y2,
              int l2x1, int l2y1, int l2x2, int l2y2,
              int l3x1, int l3y1, int l3x2, int l3y2,
              int l4x1, int l4y1, int l4x2, int l4y2,
              sOriginPlane cb);
    
protected:
    void paintEvent(QPaintEvent *local_event); // draw event with local event
    void drawLines(QPainter *local_qpainter); // draw lines with local painter
};

#endif // DRAWFIELD_H