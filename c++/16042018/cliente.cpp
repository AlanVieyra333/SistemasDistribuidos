#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <stdio.h>
#include <regex>        // Filter ip.

using namespace std;

int PORT = 7000;
int SERVERS;

// |-----| 15, 20, 25, 30, 40
// weight[] = max / i -> 2.66, 2.0, 1.6, 1.33, 1.0 = 8.59
// piece = num ÷ totalWeight × weight[i]
int main(int argc, char *argv[]){
  unsigned int num, ini, end, piece;
  bool esPrimo;
  SocketDatagrama socket = SocketDatagrama(PORT);
  SERVERS = argc - 2;
  char* ip[SERVERS];
  int port[SERVERS];
  float weight[SERVERS];
  int times[SERVERS];
  int timeMax = 0;
  float totalWeight = 0.0;

  // Get ip's and ports.
  regex rgx("([0-9]+.[0-9]+.[0-9]+.[0-9]+):([0-9]+):([0-9]+)");

  for (int i = 0, posArgs = 2; i < SERVERS; i++) {
    string arg = string(argv[posArgs++]);
    sregex_iterator it(arg.begin(), arg.end(), rgx), it_end;

    string ip_aux = (*it)[1];
    port[i] = atoi(string((*it)[2]).c_str());
    times[i] = atoi(string((*it)[3]).c_str());

    ip[i] = (char*) malloc(sizeof(char) * ip_aux.length());
    memcpy(ip[i], ip_aux.c_str(), ip_aux.length());

    if (times[i] > timeMax) timeMax = times[i];
  }

  // Calculate weight's
  for (int i = 0; i < SERVERS; i++) {
    weight[i] = ((float) timeMax) / times[i];
    totalWeight += weight[i];
  }

	//while (1){
    esPrimo = true;
    ini = 2;

		//printf("Ingrese un numero:\n");
		//scanf("%u", &num);
    num = atoi(argv[1]);

    // Send data to each server.
    for (int i = 0; i < SERVERS; i++) {
      double aux = totalWeight / weight[i];
      //printf("aux %u %f\n", num, aux);
      double pieceAux = num / aux;
      piece = num / aux;
      if((pieceAux - piece) != 0) piece++;
// n / x = n * 1/x
      end = ini + piece;
      if (i == 0) end -= 2;
      if (end >= num) end = num-1;

      unsigned int datos[] = {num , ini, end};
      ini = end + 1;

      PaqueteDatagrama datagrama = PaqueteDatagrama((char *) datos, 3 * sizeof(unsigned int), ip[i], port[i]);
      socket.envia(&datagrama);
    }

		for(int i=0; i < SERVERS; i++){
			PaqueteDatagrama datagrama =  PaqueteDatagrama(sizeof(bool));
			socket.recibe(&datagrama);
      bool result = *((bool *)datagrama.obtieneDatos());
			esPrimo = esPrimo && result;

      cout << ">> Servidor: " << datagrama.obtieneDireccion() << ":" << datagrama.obtienePuerto() << " Res: " << (result ? "True" : "False") << endl;
		}

		if (esPrimo) cout << "Si es un numero primo." << endl << endl;
		else cout << "No es un numero primo." << endl << endl;
	//}

	return 0;
}
