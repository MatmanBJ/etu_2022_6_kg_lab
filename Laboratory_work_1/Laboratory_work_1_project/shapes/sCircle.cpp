// sCircle.cpp
// This file is responsible for circle class and circle consruction

#include <QWidget>
#include <QPainter>
#include <cmath>

#include "../include_shapes/allshapes.h"

// ---------- sCircle ----------

sCircle::sCircle(sPoint center, int R, const sOriginPlane &beginOfCoords)
: point(center), r(R), origin(beginOfCoords)
{}

// ---------- sCircle ----------

sCircle::sCircle(int center_x, int center_y, int R, const sOriginPlane &beginOfCoords)
: point(center_x, center_y, beginOfCoords), r(R), origin(beginOfCoords)
{}

// ---------- sdraw ----------

void sCircle::sdraw(QPainter& local_qpainter)
{
    int x_0 = point.x(); // x coordinate
    int y_0 = point.y(); // y coodrinate
    // counting y coordinates for putting points (from start x - r to end x + r)
    for (int x = x_0 - r; x <= x_0 + r; x++)
    {
        double horde = sqrt((double)(r*r - (x - x_0)*(x - x_0))); // horde from begit to circle
        double y_new = y_0 + horde; // adding + horde to draw
        y_new = y_new < 0 ? y_new - 0.5 : y_new + 0.5; // counting nearest integer value
        int y_1 = (int)(y_new); // making an integer value

        y_new =  y_0 - horde; // adding - horde to draw
        y_new = y_new < 0 ? y_new - 0.5 : y_new + 0.5; // counting nearest integer value
        int y_2 = (int)(y_new); // making an integer value

        local_qpainter.drawPoint(x + origin.getX(), y_1 + origin.getY()); // drawing point up
        local_qpainter.drawPoint(x + origin.getX(), y_2 + origin.getY()); // drawing point down
    }
}

// ---------- getCenter ----------

sPoint sCircle::getCenter() const
{
    return point; // returning center point (with coordinates insides)
}

// ---------- getR ----------

int sCircle::getR() const
{
    return r; // returning semidiameter length
}