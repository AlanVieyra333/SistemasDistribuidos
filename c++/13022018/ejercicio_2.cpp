#include <iostream>
using namespace std;

int main( ){
	float valor1;
	float valor2;
	float valor3;
	float res1;
	float res2;
	
	cout << "Ejercicio 2: Elabore un programa para imprimir el resultado de una división entre dos enteros y de un entero con un flotante.\n";
	cout << "Introduce un número de tipo entero\n";
	cin >> valor1;
	cout << "Introduce un segundo número de tipo  entero\n";
	cin >> valor2;
	cout << "Introduce un número de tipo flotante\n";
	cin >> valor3;
	
	res1=valor1/valor2;
	res2=valor3/valor1;
	
	cout << "El cociente entre " << valor1 << " y " << valor2 << " es: " << res1 << "\n";
	cout << "El cociente entre " << valor3 << " y " << valor1 << " es: " << res2 << "\n";
	return 0;
}
