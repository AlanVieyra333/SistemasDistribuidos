#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada {
private:
	double x;
	double y;
  float magnitud;
public:
	Coordenada(double = 0, double = 0);
	double obtenerX();
	double obtenerY();
  double obtenerMagnitud();
};
#endif