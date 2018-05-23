#include "Coordenada.h"
#include <cmath>

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) { }

double Coordenada::obtenerX() {
  return x;
}

double Coordenada::obtenerY() {
  return y;
}

double Coordenada::obtenerMagnitud() {
  return sqrt(pow(x, 2) + pow(y, 2));
}
