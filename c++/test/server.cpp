#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <inttypes.h>
#include <vector>
#include <algorithm>

#define SERVER_PORT 7300

using namespace std;

struct messageSC{
  char nombre[45]; //Nombre del alumno con fin de cadena incluido
  uint32_t num[10];
};

/********************************  Main  **************************************/

int main(int argc, char* argv[]){
  SocketDatagrama socket = SocketDatagrama(SERVER_PORT);

  printf("Servidor listo\n");

  while(true) {
    uint32_t *data_req;
    messageSC data_res;
    vector<uint32_t> nums;

    PaqueteDatagrama request = PaqueteDatagrama(10 * sizeof(uint32_t));
  	socket.recibe(request);

    data_req = (uint32_t*) request.obtieneDatos();
    printf("Cliente: %s:%d -> Datos:\n", request.obtieneDireccion(), request.obtienePuerto());

    /********************************************/
    for(int i = 0; i < 10; i++) {
      //printf("%d\n", data_req[i]);
      nums.push_back(data_req[i]);
    }
    sort(nums.begin(), nums.begin() + 10);

    printf("Ordenados:\n");

    for(int i = 0; i < 10; i++) {
      data_req[i] = (uint32_t) nums[i];
      printf("%d\n", data_req[i]);
    }
    /********************************************/

    strcpy(data_res.nombre, "Name");
    memcpy(data_res.num, data_req, 10 * sizeof(uint32_t));
    
    // Send result.
    PaqueteDatagrama response =  PaqueteDatagrama((char*) &data_res, sizeof(messageSC), request.obtieneDireccion(), request.obtienePuerto());
    socket.envia(response);
  }

	return 0;
}
