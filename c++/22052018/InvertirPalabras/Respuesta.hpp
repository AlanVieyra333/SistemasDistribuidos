#include <Sockett/SocketT.hpp>
#include <Sockett/Paquete.hpp>
#include <Sockett/Paquete.hpp>

#ifndef RESPUESTA_H_
#define RESPUESTA_H_
using Mensaje = struct mensaje;
class Respuesta{
public:
    Respuesta(int pl){
        servidor = new SocketBlob100( pl );
    }
    
    Mensaje *getRequest( void ){
        PaqueteBlob100 paquetaxo(0);
        Mensaje ret;
        nBytes = servidor.recibe( paquetaxo );

        memcpy((void*) &ret,(void*)paquetaxo.obtieneDatos(), nBytes);
        return ret;
    }
    void sendReply( char *respuesta, char *ipCliente, int puertoCliente ){
        PaqueteBlob100 paquetaxo( puertoCliente );
        paquetaxo.inicializaIP( ipCliente );
        paquetaxo.inicializaIP( ipCliente );
        paquetaxo.inicializaDatos( respuesta, sizeof(respuesta) );

        servidor.envia(paquetaxo);
    }
private:
    SocketBlob100 *servidor;
};
#endif
