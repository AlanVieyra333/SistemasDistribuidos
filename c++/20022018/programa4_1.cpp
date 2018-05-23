#include "Coordenada.h"
#include "Rectangulo.h"
#include <iostream>
using namespace std;

int main() {
	//Rectangulo rectangulo1(2,3,5,1);
	Coordenada superiorIzq;
	Coordenada inferiorDer;

	//Rectangulo rectangulo1(Coordenada(2.0, 3.0), Coordenada(5.0, 1.0));
  Rectangulo rectangulo1(Coordenada(3.6055, 0.98279855), Coordenada(5.0999, 0.195954094));

	cout << "Calculando el area de un rectangulo dadas sus coordenadas en un plano cartesiano:\n";
	rectangulo1.imprimeEsq();

	cout << "El area del rectángulo es = " << rectangulo1.obtieneArea() << endl;
	return 0;
}
