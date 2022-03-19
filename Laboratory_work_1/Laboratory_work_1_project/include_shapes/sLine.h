// sLine.h
// This file is a header for "sLine.cpp" file

#ifndef SLINE_HPP
#define SLINE_HPP

#include <QWidget>
#include <QPainter>

#include "../include_shapes/allshapes.h"

// ---------- sLine ----------

class sLine
{
private:
    const sPoint p1;
    const sPoint p2;
    const sOriginPlane origin;

public:
    sLine(sPoint pointStart, sPoint pointFinish, const sOriginPlane &beginOfCoords);
    sLine(int x1, int y1, int x2, int y2, const sOriginPlane &beginOfCoords);

    void sdraw(QPainter& qp);

    sPoint getBegin() const;
    sPoint getEnd() const;
};

#endif // SLINE_HPP