/*
  g++ Fecha.cpp ejercicio_1.cpp -o a && ./a
*/
#include "Fecha.h"
#include <iostream>

using namespace std;

int main() {
  int dia = 20;
  int mes = 9;
  int anio = 2017;
  Fecha a(dia, mes, anio);
  a.muestraFecha();
}
