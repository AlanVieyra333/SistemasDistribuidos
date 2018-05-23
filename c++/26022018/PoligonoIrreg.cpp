#include "PoligonoIrreg.h"
#include <iostream>

#include <algorithm>

void PoligonoIrreg::anadeVertice(Coordenada ver){
	vertice.push_back(ver);
}

void PoligonoIrreg::imprimeVertices(){
  int i = 1;
	for(vector<Coordenada>::iterator it = vertice.begin(); it != vertice.end(); ++it, i++){
		cout << "Coordenanda " << i << ":\t(" << it->obtenerX() << "," << it->obtenerY() << ") \t\tMagnitud: " << it->obtenerMagnitud() << endl;
	}
}

bool operator<(Coordenada &coordenada1, Coordenada &coordenada2){
    return (coordenada1.obtenerMagnitud() < coordenada2.obtenerMagnitud());
}

void PoligonoIrreg::ordenar(){
  int i = 1;
  vector <Coordenada> verticesOrdenados = vertice;

  sort(verticesOrdenados.begin( ), verticesOrdenados.end( ));

	for(vector<Coordenada>::iterator it = verticesOrdenados.begin(); it != verticesOrdenados.end(); ++it, i++){
		cout << "Coordenanda " << i << ":\t(" << it->obtenerX() << "," << it->obtenerY() << ") \t\tMagnitud: " << it->obtenerMagnitud() << endl;
	}
}
