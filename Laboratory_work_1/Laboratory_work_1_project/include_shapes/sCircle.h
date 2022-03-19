// sCircle.h
// This file is a header for "sCircle.cpp" file

#ifndef SCIRCLE_HPP
#define SCIRCLE_HPP

#include <QWidget>
#include <QPainter>
#include <cmath>

#include "../include_shapes/allshapes.h"

// ---------- sCircle ----------

class sCircle
{
private:
    const sPoint point; // center point object (with coordinates inside)
    const int r; // semidiameter length
    const sOriginPlane origin; // begin of coodrdinates

public:
    sCircle(sPoint center, int R, const sOriginPlane &beginOfCoords); // constructor
    sCircle(int center_x, int center_y, int R, const sOriginPlane &beginOfCoords); // constructor
    void sdraw(QPainter& local_qpainter); // drawing circle
    sPoint getCenter() const; // getting center point
    int getR() const; // getting semidiameter length
};

#endif // SCIRCLE_HPP