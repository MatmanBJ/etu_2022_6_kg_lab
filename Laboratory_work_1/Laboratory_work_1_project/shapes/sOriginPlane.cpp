// sOriginPlane.cpp
// This file is responsible for origin plane class and origin plane consruction

// This "Origin Plane" is responsible for offset from the left hign corner.
// By default, we made the offset for X and Y as 300 and 350.

#include <QWidget>
#include <QPainter>

#include "../include_shapes/allshapes.h"

// ---------- sOriginPlane ----------

sOriginPlane::sOriginPlane(const sOriginPlane &other) // copy constructor
: _x(other.getX()), _y(other.getY())
{}

// ---------- sOriginPlane ----------

sOriginPlane::sOriginPlane() : _x(0), _y(0) // consructor default
{}

// ---------- sOriginPlane ----------

sOriginPlane::sOriginPlane(int x, int y) : _x(x), _y(y) // constructor with values
{}

// ---------- getX ----------

int sOriginPlane::getX() const // getting x
{
    return _x;
};

// ---------- getY ----------

int sOriginPlane::getY() const // getting y
{
    return _y;
};