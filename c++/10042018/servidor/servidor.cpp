#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
	SocketDatagrama socket = SocketDatagrama(7300);
	int * numeros;
	PaqueteDatagrama datagrama = PaqueteDatagrama( 2 * sizeof(int));
	socket.recibe(&datagrama);
	numeros = (int *) datagrama.obtieneDatos();

  printf("%d, %d\n", numeros[0] + numeros[1]);
	int ans = numeros[0] + numeros[1];
	cout << " Dirección " << datagrama.obtieneDireccion() <<" "<< "Puerto" << datagrama.obtienePuerto() << endl;
	PaqueteDatagrama databack =  PaqueteDatagrama((char*) &ans, sizeof(int), datagrama.obtieneDireccion(), datagrama.obtienePuerto());
	socket.envia(&databack);
	return 0;
}
