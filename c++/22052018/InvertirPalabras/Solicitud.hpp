#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

#ifndef SOLICITUD_H_
#define SOLICITUD_H_
class Solicitud
{
public:
    Solicitud();
    char * doOperation(char *IP, int puerto, int operationId, char *arguments){
        PaqueteBlob100 paquetaxo( puerto );
        paquetaxo.inicializaIP( IP );
        paquetaxo.inicializaDatos( respuesta, sizeof(respuesta) );

        servidor.envia(paquetaxo);
    }
    private:
    SocketDatagrama *socketlocal;
};
#endif
