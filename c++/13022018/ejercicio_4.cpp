#include <iostream>

using namespace std;

int main() {
  double c, f;

  cout << "Ejercicio 4. Convertir de grados Centígrados a Fahrenheit con cast.\n\n";
  cout << "Ingrese los grados Centígrados: ";
  cin >> c;
  f = (double) 9 / (double) 5 * c + 32.0;

  cout << "Grados Fahrenheit: " << f << "\n";

  return 0;
}
