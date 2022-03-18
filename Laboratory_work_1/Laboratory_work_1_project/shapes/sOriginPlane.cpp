// sOriginPlane.cpp
// This file is responsible for origin plane class and origin plane consruction

#include <QWidget>
#include <QPainter>

#include "./shapes"

// ---------- sOriginPlane ----------

sOriginPlane::sOriginPlane(const sOriginPlane &other)
: _x(other.getX()), _y(other.getY()){}

// ---------- sOriginPlane ----------

sOriginPlane::sOriginPlane() : _x(0), _y(0) {}

// ---------- sOriginPlane ----------

sOriginPlane::sOriginPlane(int x, int y) : _x(x), _y(y) {}

// ---------- getX ----------

int sOriginPlane::getX() const { return _x; };

// ---------- getY ----------

int sOriginPlane::getY() const { return _y; };