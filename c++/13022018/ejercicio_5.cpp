#include <iostream>

using namespace std;

int main() {
  int n, res;

  cout << "Ejercicio 5. Operador de incremento y decremento.\n\n";
  cout << "Ingrese el valor de n: ";
  cin >> n;

  res = n + (++n);

  cout << "El resultado de la operación 'n + (++n)' es: " << res << "\n";

  return 0;
}
