/*
  g++ Fecha.cpp ejercicio_3.cpp -o c && ./c
*/
#include "Fecha.h"
#include <iostream>

using namespace std;

int main() {
  Fecha a, b, c(21, 9, 1973);

  b.inicializaFecha(17, 6 , 2000);
  a.muestraFecha();
  cout << "Su conversión es: " << a.convierte() << endl;
  b.muestraFecha();
  cout << "Su conversión es: " << b.convierte() << endl;
  c.muestraFecha();
  cout << "Su conversión es: " << c.convierte() << endl;
}
