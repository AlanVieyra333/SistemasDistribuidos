#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

#ifndef PAQUETE_H_
#define PAQUETE_H_

template<class T>
class Paquete{
    private :
        T datos;
        char ip[16];
        unsigned longitud;
        int puerto;

    public:
        Paquete( int pto ){
            this->puerto = pto;
        }

        char *obtieneDireccion() {
            return this->ip;
        }
        unsigned int obtieneLongitud(){
            return this->longitud;
        }
        int obtienePuerto(){
            return this->puerto;
        }
        T  obtieneDatos(){
            return this->datos;
        }
        void inicializaPuerto(int pto) {
            this->puerto = pto;
        }
        void inicializaIP(char *dirip) {
            strcpy(this->ip,dirip);
        }
        void inicializaDatos(T &data) {
            this->datos = data;
        };
};

/*
 * Paqueteblob100:
 *      Para tratar con apuntadores y tamaños de paquete fijos, se tuvo que crear una especialización del
 *      template Paquete.
 *      Además de eso, la principal diferencia con el template es el cambio de las funciones strcpy por
 *      memcpy(). Por alguna razón que no he encontrado en la documentación, strcpy() modifica los
 *      caracteres para intentar hacerlos legibles, lo cual afecta a los archivos que no contienen texto
 *      plano. memcpy() en cambio hace esta copia de manera transparente.
 *      TODO: en la practica encontré que todas las copias a buffer se hacen sobre los mismos apuntadores,
 *      quizá sea más eficiente no utilizar tantas veces inicializaDatos(). Además, es mucho más seguro
 *      utilizar la función inicializaDatos(char*,size_t), pues se puede llevar mejor control del tamaño
 *      exacto del paquete. Ésto mientras no se encuentre una forma de automatizar el proceso de manipular
 *      estos tamaños.
*/

class PaqueteBlob100{
    private:
        char datos[1200];
        size_t longitud;
        int puerto;
        char ip[16];

    public:
        PaqueteBlob100( int pto):puerto(pto){};

        char* obtieneDireccion() {
            return this->ip;
        }
        int obtienePuerto(){
            return this->puerto;
        }
        size_t obtieneLongitud(){
            return this->longitud;
        }
        char* obtieneDatos(){
            return this->datos;
        }

        void inicializaPuerto(int pto) {
            this->puerto = pto;
        }
        void inicializaIP(char *dirip) {
            strcpy(this->ip,dirip);
        }
        void inicializaDatos(char *data) {
            this->longitud = 1200;
            bzero( this->datos, 1200 );
            memcpy(this->datos,data, 1200);
        };
        void inicializaDatos(char *data, size_t size) {
            this->longitud = size;
            bzero( this->datos, 1200 );
            memcpy(this->datos, data, size);
        };
};
#endif
