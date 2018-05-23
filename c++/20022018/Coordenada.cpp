#include "Coordenada.h"
#include <cmath>
#include <iostream>
using namespace std;

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) { }

double Coordenada::obtenerX() {
  //return x;
  return (x * cos(y));
}

double Coordenada::obtenerY() {
  //return y;
  return (x * sin(y));
}
