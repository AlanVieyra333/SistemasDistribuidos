#include <iostream>

using namespace std;

int main() {
  int n;
  string line;
  cin >> n;
  getline(cin, line);

  cout << "No funciona como se espera debido a que la funcion 'getline'\nlee el salto de linea despues del número ingresado.\n";

  return 0;
}
