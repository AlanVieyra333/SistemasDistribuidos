#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

/* 18 seg en 1 maquina*/
bool numPrimo(unsigned int num, unsigned int ini, unsigned int fin){
	for (int actual = ini; actual <= fin; actual++){
		if(num%actual == 0)
			return false;
	}
	return true;
}

int main(int argc, char* argv[]){
  int PORT = atoi(argv[1]);
  SocketDatagrama socket = SocketDatagrama(PORT);
	int parametros[3];

	while(1){
		PaqueteDatagrama datagrama = PaqueteDatagrama(3 * sizeof(int));
		socket.recibe(&datagrama);

		memcpy(parametros, datagrama.obtieneDatos(), 3 * sizeof(int));

    int num = parametros[0];
    int ini = parametros[1];
    int fin = parametros[2];
    printf("ok %d %d %d \n", num, ini, fin);
    cout << " Dirección " << datagrama.obtieneDireccion() <<" "<< "Puerto" << datagrama.obtienePuerto() << endl;
		bool ans = numPrimo(num, ini, fin);


		PaqueteDatagrama databack =  PaqueteDatagrama((char*) &ans, sizeof(bool), datagrama.obtieneDireccion(), datagrama.obtienePuerto());
		socket.envia(&databack);
	}
	return 0;
}
