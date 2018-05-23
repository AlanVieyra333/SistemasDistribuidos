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
	
	int * ans = (int *)malloc(sizeof(int));
	*ans = numeros[0] + numeros[1];
	cout 	<< "Numeros recibidos " << numeros[0] << " y " << numeros[1] 
			<< " de " << datagrama.obtieneDireccion() << ":" << datagrama.obtienePuerto() << endl;
	PaqueteDatagrama databack =  PaqueteDatagrama((char*) ans, sizeof(int), datagrama.obtieneDireccion(), datagrama.obtienePuerto());
	socket.envia(&databack);
	return 0;
}