#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

/* 18 seg en 1 maquina (Erick), 41 seg 1 maquina (Vieyra)  -> Razon 1:2.27  -> 1:2.3*/
bool esPrimo(unsigned int num, unsigned int ini, unsigned int fin){
	for (int actual = ini; actual <= fin; actual++){
		if(num%actual == 0 && actual < num && actual > 1)
			return false;
	}

	return true;
}

int main(int argc, char* argv[]){
  int PORT = atoi(argv[1]);
	SocketDatagrama socket = SocketDatagrama(PORT);
  unsigned int parametros[3];

  printf("Servidor listo en el puerto:%d\n", PORT);

  while(1){
  	PaqueteDatagrama datagrama = PaqueteDatagrama(3 * sizeof(unsigned int));
  	socket.recibe(&datagrama);

    memcpy(parametros, datagrama.obtieneDatos(), 3 * sizeof(unsigned int));

    printf("Cliente: %s:%d {%u, [%u, %u]}\n", datagrama.obtieneDireccion(), datagrama.obtienePuerto(), parametros[0], parametros[1], parametros[2]);

    bool ans = esPrimo(parametros[0],  parametros[1], parametros[2]);
    PaqueteDatagrama databack =  PaqueteDatagrama((char*) &ans, sizeof(bool), datagrama.obtieneDireccion(), datagrama.obtienePuerto());
  	socket.envia(&databack);
  }
	return 0;
}
