#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include "Coordenada.h"
#include <vector>

using namespace std;

class PoligonoIrreg {
private:
	vector <Coordenada> vertice;

public:
	void anadeVertice(Coordenada);
	void imprimeVertices();
  void ordenar();
};

#endif
