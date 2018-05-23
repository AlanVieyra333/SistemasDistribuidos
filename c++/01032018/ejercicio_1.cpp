#include <cmath>
#define MAX 15000000

double seno = 0, coseno = 0, tangente = 0, logaritmo = 0, raizCuad = 0;

void process() {
  for (double i = 0.0; i < MAX; i++) {
    seno += sin(i);
    coseno += cos(i);
    tangente += tan(i);
    logaritmo += log10(i);
    raizCuad += sqrt(i);
  }
}

int main() {
  process();

  return 0;
}
