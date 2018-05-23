#include "Paquete.hpp"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>
#ifndef SOCKETT_HPP_
#define SOCKETT_HPP_

using ptrDireccionSocket = struct sockaddr *;

template<class T>
class SocketT{
    public:
        int puerto;
        struct sockaddr_in direccionLocal;
        struct sockaddr_in direccionForanea;
        int descriptorArchivo;

    public:
        SocketT( int puerto ) {
            this->descriptorArchivo = socket(AF_INET, SOCK_DGRAM,0);
            bzero((char *)&this->direccionLocal,sizeof(this->direccionLocal));

            this->direccionLocal.sin_family = AF_INET;
            this->direccionLocal.sin_addr.s_addr=INADDR_ANY;
            this->direccionLocal.sin_port = htons(puerto);

            int res = bind( this->descriptorArchivo,
                 (ptrDireccionSocket )&this->direccionLocal,
                 sizeof(this->direccionLocal)
                );
            if( res < 0 ){
                std::cout << puerto << "\n";
                perror("bind");
                exit(1);
            }
            else{
                std::cout << "Escuchando en puerto "<< puerto << "\n";
            }
        }

        SocketT(Paquete<T> &p) {
            this->descriptorArchivo = socket(AF_INET, SOCK_DGRAM,0);
            bzero((char *)&this->direccionLocal,sizeof(this->direccionLocal));
            this->direccionLocal.sin_family      = AF_INET;
            this->direccionLocal.sin_addr.s_addr = p.obtieneDireccion();
            this->direccionLocal.sin_port        = p.obtienePuerto();
            bind( this->descriptorArchivo,
                 (ptrDireccionSocket )&this->direccionLocal,
                 sizeof(this->direccionLocal)
                );
        }

        ~SocketT(){
            close(this->descriptorArchivo);
        }

        T recibe(Paquete<T> &p) {
            socklen_t lon = sizeof(this->direccionForanea);
            T rtn;
            int aux = recvfrom( this->descriptorArchivo,
                                (void*) &rtn,
                                sizeof(T),
                                0,
                                (ptrDireccionSocket)&this->direccionForanea,
                                &lon
                            );
            p.inicializaDatos( rtn );
            p.inicializaIP( inet_ntoa( this->direccionForanea.sin_addr ) );
            p.inicializaPuerto( htons( this->direccionForanea.sin_port ) );
            return rtn;
        }


        T envia(Paquete<T> &p) {
            T dato = p.obtieneDatos();
            bzero( (char *)&this->direccionForanea, sizeof(this->direccionForanea) );
            this->direccionForanea.sin_family = AF_INET;
            this->direccionForanea.sin_port = htons( p.obtienePuerto() );
            this->direccionForanea.sin_addr.s_addr = inet_addr( p.obtieneDireccion() );
            int aux = sendto( this->descriptorArchivo,
                            (void *) &dato,
                            sizeof(T),
                            0,
                            (ptrDireccionSocket) &this->direccionForanea,
                            sizeof( this->direccionForanea ) );
            return dato;
        }
};

/*
 * SocketBlob100:
 *      Para tratar con apuntadores y tamaños de paquete fijos, se tuvo que crear una especialización del
 *      template SocketT.
 *      La principal diferencia es que utiliza a PaqueteBlob100 y que, desde éste, obtiene los tamaños de
 *      los buffers a enviar.
*/
class SocketBlob100{
    public:
        int puerto;
        struct sockaddr_in direccionLocal;
        struct sockaddr_in direccionForanea;
        int descriptorArchivo;

    public:
        SocketBlob100( int puerto ) {
            this->descriptorArchivo = socket(AF_INET, SOCK_DGRAM,0);
            bzero((char *)&this->direccionLocal,sizeof(this->direccionLocal));

            this->direccionLocal.sin_family = AF_INET;
            this->direccionLocal.sin_addr.s_addr=INADDR_ANY;
            this->direccionLocal.sin_port = htons(puerto);

            int res = bind( this->descriptorArchivo,
                 (ptrDireccionSocket )&this->direccionLocal,
                 sizeof(this->direccionLocal)
                );
            if( res < 0 ){
                std::cout << puerto << "\n";
                perror("bind");
                exit(1);
            }
            else{
                int prtAsignado = htons( this->direccionLocal.sin_port );
                std::cout << "Escuchando en puerto "<< prtAsignado << "\n";
            }
        }

        ~SocketBlob100(){
            close(this->descriptorArchivo);
        }

        int recibe(PaqueteBlob100 &p) {
            socklen_t lon = sizeof(this->direccionForanea);
            char rtn[1200];
            int aux = recvfrom( this->descriptorArchivo,
                                (void*) rtn,
                                sizeof(rtn),
                                0,
                                (ptrDireccionSocket)&this->direccionForanea,
                                &lon
                            );
            if( aux < 1 ){
                perror("recvfrom");
                exit(1);
            }
            p.inicializaDatos( rtn, aux );
            p.inicializaIP( inet_ntoa( this->direccionForanea.sin_addr ) );
            p.inicializaPuerto( htons( this->direccionForanea.sin_port ) );
            return aux;
        }


        int envia(PaqueteBlob100 & pack) {
            char *dato = pack.obtieneDatos();

            bzero( (char *)&this->direccionForanea, sizeof(this->direccionForanea) );

            this->direccionForanea.sin_family = AF_INET;
            this->direccionForanea.sin_port = htons( pack.obtienePuerto() );
            this->direccionForanea.sin_addr.s_addr = inet_addr( pack.obtieneDireccion() );

            int aux = sendto( this->descriptorArchivo,
                            (void *) dato,
                            pack.obtieneLongitud(),
                            0,
                            (ptrDireccionSocket) &this->direccionForanea,
                            sizeof( this->direccionForanea ) );

            if( aux < 1 ){
                perror("sendto");
                exit(1);
            }
            return aux;
        }
};


#endif
