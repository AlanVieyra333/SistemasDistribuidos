#include "Point.h"

Point::Point() {
  setX(0);
  setY(0);
}

Point::Point(double x, double y) {
  setX(x);
  setY(y);
}

void Point::setX(double x) {
  this->x = x;
}

void Point::setY(double y) {
  this->y = y;
}

double Point::getX() {
  return x;
}

double Point::getY() {
  return y;
}
