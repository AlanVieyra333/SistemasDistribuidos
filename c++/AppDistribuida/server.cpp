#include <bits/stdc++.h>
#include <PaqueteDatagrama.h>
#include <SocketDatagrama.h>
#include <Point.h>
#include <gfx.h>
#include <thread>
#include <vector>

#define TIME_SLEEP 41666  // Time for sleep in microseconds (24 imgs/seg.).

using namespace std;

double x_last = -1, y_last = -1, x, y;
vector<Point> points;

void drawScreen();
void drawPoints();

int main(int argc, char* argv[]){
  int PORT = atoi(argv[1]);
	SocketDatagrama socket = SocketDatagrama(PORT);
  double *parametros;

  printf("Servidor listo en el puerto:%d\n", PORT);

  gfx_open(800, 600, "Equipo 4");
  gfx_clear_color(224, 255, 255);
  //gfx_color(255, 0, 0);
  gfx_color(100, 100, 100);

  thread drawing(drawScreen);

  /*while (true) {
    gfx_clear();

    gfx_line(x_last, y_last, x, y);

    gfx_flush();
    usleep(TIME_SLEEP);
  }
  //*/

  while(true){
    PaqueteDatagrama datagrama = PaqueteDatagrama(2 * sizeof(double));
  	socket.recibe(datagrama);

    char* tmp = (char*) datagrama.obtieneDatos();
    //memcpy(parametros, datagrama.obtieneDatos(), 1 * sizeof(double));
    char voleado[2][8];

    for (int i = 0; i < 8; i++) {
      voleado[0][i] = tmp[7-i];
      voleado[1][i] = tmp[15-i];
      //printf("%d ", voleado[i]);
    }
    //printf("\n");
    parametros = (double*) voleado;

    x = parametros[0];
    y = parametros[1];

    points.push_back(Point(x, y));
    //printf("Cliente: %s:%d -> Datos: %f, %f\n", datagrama.obtieneDireccion(), datagrama.obtienePuerto(), parametros[0], parametros[1]);

    /*gfx_clear();

    gfx_line(x_last, y_last, x, y);
    x_last = x;
    y_last = y;

    gfx_flush();*/
    //usleep(TIME_SLEEP);
  }

	return 0;
}

void drawScreen() {
  while(true){
    gfx_clear();

    drawPoints();

    gfx_flush();
    usleep(TIME_SLEEP);
  }
}

void drawPoints() {

  gfx_line(0, 300, 800, 300);
  gfx_line(400, 0, 400, 600);

  if (points.size()  > 0)
    for (int i = 0; i < points.size() - 1; i++) {
      Point a = points[i];
      Point b = points[i + 1];

      gfx_line(a.getX(), a.getY(), b.getX(), b.getY());
    }
}
