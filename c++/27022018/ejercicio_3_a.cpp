#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string>

using namespace std;

int count, pos;
string cadenota;

void generateStr(int n) {
  for (int i = 0; i < n; i++) {
    char char1 = (rand() % 26) + 65;
    char char2 = (rand() % 26) + 65;
    char char3 = (rand() % 26) + 65;

    string strAux = string(1, char1) + "" + char2 + "" + char3;
    cadenota += (i > 0) ? " " + strAux : strAux;
  }
}

void searchWord(string str) {
  while ( (pos = cadenota.find(str, pos + 1)) != -1) {
    count++;
  }
}

int main() {
  count = 0;
  pos = -1;
  cadenota = "";

  srand (time(NULL));
  // Generate string.
  // Probabilidad: 1 / (26 * 26 * 26) ; por lo que se necesitan 17576 intentos
  generateStr(17576 * 15);
  // Search "IPN".
  searchWord("IPN");

  cout << "Ocurrencias: " << count << endl;

  return 0;
}
