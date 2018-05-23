#ifndef SPIDER_H_
#define SPIDER_H_

#include "Point.h"
#include "gfx.h"
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Spider {
  private:
    int id;                 // {1, 2, 3, 4}
    vector<Point> points;   // Points that describe the shape of the asteroid.
    Point position;         // Position x, y.
    Point lastPosition = Point(-1, -1);     // Last position x, y.
    double direction;       // In degrees. [0, 2*pi]
    vector<Point> travel;
    double distanceTraveled = 0;
    // Connection.
    string ip;
    int port;

    double getDistance(Point a, Point b);
    double getM(Point a, Point b);
    double getTheta(double m);
  public:
    Spider(int id, string ip, int port);
    void setPosition(double x, double y);
    Point getPosition();
    int getId();
    string getIp();
    int getPort();
    double getDistanceTraveled();
    vector<Point> getPoints();
    void draw();
    void drawTravel();
    void rotate(double angle);
};

#endif
