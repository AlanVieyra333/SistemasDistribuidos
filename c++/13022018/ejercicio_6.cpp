#include <iostream>
using namespace std;

int main( ){
	cout << "Ejercicio 6: Imprima la variable precio después de hacer la siguiente asignación: 'double precio 78.7'\n";
	double precio = 78.7;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "Impresion del número: " << precio << "\n" ;
	
	return 0;
}
