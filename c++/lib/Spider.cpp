#include "Spider.h"

Spider::Spider(int id, string ip, int port) {
  this->id = id;
  this->ip = ip;
  this->port = port;
  int scale = 5;

  // Generate spider points.
  // Body
  points.push_back(Point(scale * 0, scale * 2));
  points.push_back(Point(scale * 1, scale * 0));
  points.push_back(Point(scale * 1, scale * -2));
  points.push_back(Point(scale * 0, scale * -3));
  points.push_back(Point(scale * -1, scale * -2));
  points.push_back(Point(scale * -1, scale * 0));
  points.push_back(Point(scale * 0, scale * 2));  // 6
  // Food 1.
  points.push_back(Point(scale * 1, scale * 0));
  points.push_back(Point(scale * 2, scale * 1));
  points.push_back(Point(scale * 2, scale * 3));
  points.push_back(Point(scale * 1, scale * 4));  // 10
  // Food 2.
  points.push_back(Point(scale * 1, scale * 0));
  points.push_back(Point(scale * 2, scale * 0));
  points.push_back(Point(scale * 3, scale * 1));
  points.push_back(Point(scale * 3, scale * 3));
  points.push_back(Point(scale * 2, scale * 4));  // 15
  // Food 3.
  points.push_back(Point(scale * -1, scale * 0));
  points.push_back(Point(scale * -2, scale * 1));
  points.push_back(Point(scale * -2, scale * 3));
  points.push_back(Point(scale * -1, scale * 4)); // 19
  // Food 4.
  points.push_back(Point(scale * -1, scale * 0));
  points.push_back(Point(scale * -2, scale * 0));
  points.push_back(Point(scale * -3, scale * 1));
  points.push_back(Point(scale * -3, scale * 3));
  points.push_back(Point(scale * -2, scale * 4)); // 24
  // Food 5.
  points.push_back(Point(scale * 1, scale * -1));
  points.push_back(Point(scale * 2, scale * -2));
  points.push_back(Point(scale * 2, scale * -4));
  points.push_back(Point(scale * 1, scale * -5)); // 28
  // Food 6.
  points.push_back(Point(scale * 1, scale * -1));
  points.push_back(Point(scale * 2, scale * -1));
  points.push_back(Point(scale * 3, scale * -2));
  points.push_back(Point(scale * 3, scale * -4));
  points.push_back(Point(scale * 2, scale * -5)); // 33
  // Food 7.
  points.push_back(Point(scale * -1, scale * -1));
  points.push_back(Point(scale * -2, scale * -2));
  points.push_back(Point(scale * -2, scale * -4));
  points.push_back(Point(scale * -1, scale * -5)); // 37
  // Food 8.
  points.push_back(Point(scale * -1, scale * -1));
  points.push_back(Point(scale * -2, scale * -1));
  points.push_back(Point(scale * -3, scale * -2));
  points.push_back(Point(scale * -3, scale * -4));
  points.push_back(Point(scale * -2, scale * -5));

  switch (id) {
    case 2:
      rotate(-M_PI/2.0);
      break;
    case 3:
      rotate(M_PI);
      break;
    case 4:
      rotate(M_PI/2.0);
      break;
  }
}

void Spider::setPosition(double x, double y) {
  if (lastPosition.getX() != -1) {
    lastPosition.setX(position.getX());
    lastPosition.setY(position.getY());

    position.setX(x);
    position.setY(y);

    distanceTraveled += getDistance(lastPosition, position);
  }else {
    distanceTraveled = 0;

    lastPosition.setX(x);
    lastPosition.setY(y);
    position.setX(x);
    position.setY(y);
  }

  travel.push_back(position);

  //rotate(getTheta(getM(lastPosition, position)));
}

Point Spider::getPosition() {
  return position;
}

int Spider::getId() {
  return id;
}

string Spider::getIp() {
  return ip;
}

int Spider::getPort() {
  return port;
}

double Spider::getDistanceTraveled() {
  return distanceTraveled;
}

vector<Point> Spider::getPoints() {
  return points;
}

void Spider::draw() {
  for (int i = 0; i < points.size() - 1; i++) {
    if(i == 7 || i == 10 || i == 15 || i == 19 ||
      i == 24 || i == 28 || i == 33 || i == 37)
      i++;

    Point a = points[i];
    Point b = points[i + 1];

    gfx_line(position.getX() + a.getX(),
      position.getY() + a.getY(),
      position.getX() + b.getX(),
      position.getY() + b.getY());
  }
}

void Spider::drawTravel() {
  for (int i = 0; i < travel.size() - 1; i++) {
    Point a = travel[i];
    Point b = travel[i + 1];

    gfx_line(a.getX(), a.getY(), b.getX(), b.getY());
  }
}

void Spider::rotate(double angle) {
  double x, y, xx, yy;

  for (int i = 0; i < points.size(); i++) {
    x = points[i].getX();
    y = points[i].getY();

    xx = x * cos(angle) - y * sin(angle);
    yy = x * sin(angle) + y * cos(angle);

    points[i].setX(xx);
    points[i].setY(yy);
  }
}

double Spider::getDistance(Point a, Point b) {
  return sqrt(pow(b.getX() - a.getX(), 2.0) + pow(b.getY() - a.getY(), 2.0));
}

double Spider::getM(Point a, Point b) {
  return (b.getY() - a.getY()) / (b.getX() - a.getX());
}

double Spider::getTheta(double m) {
  return atan(m);
}
