#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
using namespace std;
int main()
{
	SocketDatagrama socket = SocketDatagrama(7000);
	int numeros[2];
	numeros[0] = 1;
	numeros[1] = 3;
	PaqueteDatagrama datagrama = PaqueteDatagrama((char *) numeros, 2 * sizeof(int),"127.0.0.1", 7300);
	socket.envia(&datagrama);
	
	PaqueteDatagrama databack =  PaqueteDatagrama(sizeof(int));
	socket.recibe(&databack);
	int * ans = (int*)databack.obtieneDatos();
	cout << (*ans) << endl;
	return 0;
}