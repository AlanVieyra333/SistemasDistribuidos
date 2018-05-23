#include "PoligonoIrreg.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

using namespace std;

int main() {
	PoligonoIrreg vertice;
  int n = 10;

  srand (time(NULL));

	for (int i = 0; i < n; i++) {
    /* code */
    int irand = rand() % 200  - 100;
    float frand = (rand() % 1000) / 1000.0;
    float crand1 = irand + frand;
    int irand2 = rand() % 200  - 100;
    float frand2 = (rand() % 1000) / 1000.0;
    float crand2 = irand2 + frand2;

    vertice.anadeVertice(Coordenada(crand1, crand2));
  }

  vertice.imprimeVertices();
  cout << "________________________\n";
  vertice.ordenar();

	return 0;
}
