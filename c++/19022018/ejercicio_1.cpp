/*
  g++ Fecha.cpp ejercicio_1.cpp -o a && time ./a
*/
#include "Fecha.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

using namespace std;

/*
int masVieja(Fecha *fecha1, Fecha *fecha2){
	if(fecha1->convierte() < fecha2->convierte())
		return 1;
	else if(fecha1->convierte() == fecha2->convierte() )
		return 0;
	else
		return -1;
}*/

int masVieja(Fecha fecha1, Fecha fecha2){
	if(fecha1.convierte() < fecha2.convierte())
		return 1;
	else if(fecha1.convierte() == fecha2.convierte() )
		return 0;
	else
		return -1;
}


int main() {
  int dia = 20;
  int mes = 9;
  int anio = 2017;

  srand (time(NULL));

  for(int i=0; i<100000; i++){
	  dia = rand() % 31 + 1;
	  mes = rand() % 12 + 1;
	  anio = rand() % 2018 + 1;
	  Fecha a(dia, mes, anio);

	  dia = rand() % 31 + 1;
	  mes = rand() % 12 + 1;
	  anio = rand() % 2018 + 1;
	  Fecha b(dia, mes, anio);

//	  masVieja(&a, &b);
	  masVieja(a, b);
  }
}
