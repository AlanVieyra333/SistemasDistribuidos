#ifndef POINT_H_
#define POINT_H_

class Point {
	private:
    double x;
    double y;
  public:
    Point();
    Point(double x, double y);
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
};

#endif
