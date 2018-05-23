#include "Solicitud.h"
#include "mensaje.h"
#include <stdlib.h>
#include <time.h>

#define IDS 1000

Solicitud::Solicitud() {
  socketlocal = new SocketDatagrama(0);
  srand(time(NULL));
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments) {
  mensaje msg;
  // Llenar datos.
  msg.messageType = 0;
  msg.requestId = rand() % IDS;
  memcpy(msg.IP, IP, 16 * sizeof(char));
  msg.puerto = puerto;
  msg.operationId = operationId;
  memcpy(msg.arguments, arguments, TAM_MAX_DATA);

  PaqueteDatagrama datagrama = PaqueteDatagrama((char*) &msg, sizeof(mensaje), IP, puerto);
  socketlocal->envia(datagrama);
}

