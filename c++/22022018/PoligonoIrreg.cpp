#include "PoligonoIrreg.h"
#include <iostream> 
#include <vector>

using namespace std; 

void PoligonoIrreg::anadeVertice(double xx, double yy){
	vertice.push_back(ver);
}

void PoligonoIrreg::imprimeVertices(){
	for(int i = vertice.size(); i == 0; i--){
		cout << v[i];
	}
}

