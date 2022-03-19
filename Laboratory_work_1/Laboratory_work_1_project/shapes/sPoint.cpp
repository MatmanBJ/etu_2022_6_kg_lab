// sPoint.cpp
// This file is responsible for point class and point consruction

#include <QWidget>
#include <QPainter>

#include "../include_shapes/allshapes.h"

// ---------- sPoint ----------

sPoint::sPoint(int X, int Y, const sOriginPlane &beginOfCoords)
: _x(X), _y(Y), origin(beginOfCoords)
{}

// ---------- sDraw ----------

void sPoint::sdraw(QPainter& qp)
{
    qp.drawPoint(x() + origin.getX(), y() + origin.getY());
}

// ---------- getX ----------

int sPoint::getX() const
{
    return _x;
}

// ---------- getY ----------

int sPoint::getY() const
{
    return _y;
}

// ---------- setX ----------

void sPoint::setX(int new_x)
{
    _x = new_x;
}

// ---------- setY ----------

void sPoint::setY(int new_y)
{
    _y = new_y;
}

// ---------- x ----------

int sPoint::x() const
{
    return getX();
}

// ---------- y ----------

int sPoint::y() const
{
    return getY();
}