#include <iostream>

using namespace std;

int main() {
  double c, f;

  cout << "Ejercicio 3. Convertir de grados Centígrados a Fahrenheit con static_cast<>.\n\n";
  cout << "Ingrese los grados Centígrados: ";
  cin >> c;
  f = static_cast<double>(9)/static_cast<double>(5) * c + 32.0;

  cout << "Grados Fahrenheit: " << f << "\n";

  return 0;
}
