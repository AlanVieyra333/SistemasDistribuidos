#ifndef POLIGONOIRREG_H_ 
#define POLIGONOIRREG_H_ 
#include "Coordenada.h"

class PoligonoIrreg {
private:
	vector <Coordenada> vertice;
public:
	void anadeVertice(double = 0, double = 0);
	void imprimeVertices();
};

#endif  
