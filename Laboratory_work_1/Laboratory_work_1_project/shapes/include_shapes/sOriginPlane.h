// sOriginPlane.h
// This file is a header for "sOriginPlane.cpp" file

#ifndef SORIGINPLANE_H
#define SORIGINPLANE_H


#include <QWidget>
#include <QPainter>

#include "../shapes"

class sOriginPlane
{
    private:
    const int _x;
    const int _y;

    public:

    sOriginPlane(const sOriginPlane &other);

    sOriginPlane();

    sOriginPlane(int x, int y);

    //sPoint getCoord();

    int getX() const;

    int getY() const;
};


#endif // SORIGINPLANE_H