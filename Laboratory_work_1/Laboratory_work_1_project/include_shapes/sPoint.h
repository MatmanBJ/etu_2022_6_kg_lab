// sPoint.h
// This file is a header for "sPoint.cpp" file

#ifndef SPOINT_H
#define SPOINT_H

#include <QWidget>
#include <QPainter>

#include "../include_shapes/allshapes.h"

// ---------- sPoint ----------

class sPoint
{
private:
    int _x;
    int _y;
    const sOriginPlane origin;

public:
    sPoint(int x, int y, const sOriginPlane &beginOfCoords);

    void sdraw(QPainter& qp);

    int getX() const;
    int getY() const;
    
    void setX(int new_x);
    void setY(int new_y);

    int x() const;
    int y() const;
};

#endif // SPOINT_H