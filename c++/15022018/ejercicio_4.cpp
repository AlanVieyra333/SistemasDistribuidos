#include "Fecha.h"
#include <iostream>
using namespace std;

int main(){
	Fecha a(1, 2, 1995), b(1, 2, 1996);
	int count = 0;

	a.muestraFecha();
	a.leapyr();
	b.muestraFecha();
	b.leapyr();

	for(int i=1; i<=2018; i++) {
		Fecha x(1, 1, i);
		if(x.leapyr()) {
			count++;
		}
	}

	cout << "Existen " << count << " anios bisiestos. entre el anio 1 y 2018\n";
}
