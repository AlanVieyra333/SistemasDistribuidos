#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

	SocketDatagrama socket = SocketDatagrama(7000);
	char* ip = argv[1];
	int numeros[2];
	numeros[0] = 2;
	numeros[1] = 5;
	PaqueteDatagrama datagrama = PaqueteDatagrama((char *) numeros, 2 * sizeof(int),ip, 7300);
	socket.envia(&datagrama);

	PaqueteDatagrama databack =  PaqueteDatagrama(sizeof(int));
	socket.recibe(&databack);
	int * ans = (int*)databack.obtieneDatos();
	cout
			<< " Dirección " << datagrama.obtieneDireccion() << " puerto: " << datagrama.obtienePuerto() << endl;
	cout << "2 + 5 = "<<(*ans) << endl;
	return 0;
}
