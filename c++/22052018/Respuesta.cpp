#include "Respuesta.h"
#include "mensaje.h"

Respuesta::Respuesta(int pl) {
  socketlocal = new SocketBlob100( pl );
}

void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente) {
  PaqueteBlob100 paquetaxo( puertoCliente );
  paquetaxo.inicializaIP( ipCliente );
  paquetaxo.inicializaIP( ipCliente );
  paquetaxo.inicializaDatos( respuesta, sizeof(respuesta) );

  servidor.envia(paquetaxo);
}
