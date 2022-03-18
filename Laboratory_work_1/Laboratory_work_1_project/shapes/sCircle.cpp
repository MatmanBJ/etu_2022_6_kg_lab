// sCircle.cpp
// This file is responsible for circle class and circle consruction

#include <QWidget>
#include <QPainter>
#include <cmath>

#include "./shapes"

// ---------- sCircle ----------

sCircle::sCircle(sPoint center, int R, const sOriginPlane &beginOfCoords)
: p0(center), r(R), origin(beginOfCoords)
{}

// ---------- sCircle ----------

sCircle::sCircle(int center_x, int center_y, int R, const sOriginPlane &beginOfCoords)
: p0(center_x, center_y, beginOfCoords), r(R), origin(beginOfCoords)
{}

// ---------- sdraw ----------

void sCircle::sdraw(QPainter& qp)
{
    int x0 = p0.x();
    int y0 = p0.y();
    for (int x = x0-r; x <= x0+r; ++x)
    {
        double sq = sqrt((double)(r*r - (x-x0)*(x-x0)));
        double buff = sq + y0;
        buff = buff < 0 ? buff-0.5: buff+0.5;
        int y1 = (int)(buff);

        buff = -sq + y0;
        buff = buff < 0 ? buff-0.5: buff+0.5;
        int y2 = (int)(buff);

        qp.drawPoint(x+origin.getX(), y1+origin.getY());
        qp.drawPoint(x+origin.getX(), y2+origin.getY());
    }
}

// ---------- getCenter ----------

sPoint sCircle::getCenter() const
{
    return p0;
}

// ---------- getR ----------

int sCircle::getR() const
{
    return r;
}