#ifndef PROTOCOLOS_HPP_
#define PROTOCOLOS_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Paquete.hpp"
#include "SocketT.hpp"


namespace ProSock{
    //Se necesita una cadena para avisar que un archivo termino de enviarse
    const char ENDSTR[] = "OKOKOKOKOKOKOK0000000000";

    void RecibirPaquetes( int puerto, std::string dir ) {
        SocketBlob100 servidor(puerto);
        PaqueteBlob100 paquetaxo(0);

        //hilo princial
        while(true){
            std::string path(dir);
            int nBytes;
            int packs=0;
            //todo: separar cada intento de conexion a un hilo y asociar los buffers a una IP
            nBytes = servidor.recibe( paquetaxo );
            //std::stringstream no codifica texto, sino almacena streams de datos crudos.
            std::stringstream buff;

            //truckazo para concatenar char*
            path += paquetaxo.obtieneDatos();
            //mientras no se envie la cadena de fin, se recibirá información guardandóla en un buffer
            while( true ){
                nBytes = servidor.recibe( paquetaxo );
                packs++;//meramente informativo y para debuggeo

                char *aux = paquetaxo.obtieneDatos();//todo: optimizar ésto

                //si la cádena de fin tuviese que ser binaria, se debe cambiar este método.
                // De igual forma puede provocar errores para archivos binarios.
                if( strcmp( aux, ENDSTR ) == 0 ){
                    break;
                }else{
                    //Utilizar write() en objetos que decienden de std::ofstream nos permite guardar información
                    //binaria
                    buff.write(aux, nBytes);
                }
            }
            //Debug: buff.gcount devuelve la cantidad de caracteres extraídos, no la almacenada en buffer.
            std::cout << "Escribiendo: \n"<< path <<" de tamanio "<<buff.gcount()<< " recibido en "<< packs << " Paquetes\n";
            std::ofstream destino(path,  std::ios::out | std::ios::binary);
            destino<<buff.rdbuf();
            destino.close();
        }
    }

    void EnviarPaquetes( std::string sendIP, int puertoEspejo, std::string path, std::string file ){
        SocketBlob100 socks(0); //Duando se inicializa a 0, el SO elige un puerto disponible.

        PaqueteBlob100 paquetaxo( puertoEspejo );

        char IP[] = "127.0.0.1";
        strcpy( IP, sendIP.c_str() );
        paquetaxo.inicializaIP( IP );

        //se debe asegurar que todos los buffers de salida se limpien con ceros para que todas las funciones
        //de escritura y lectura, funcionen correctamente.
        char memblock[1200];
        bzero( memblock, 1200 );

        //puesto que el nombre del archivo debe ser un texto, es correcto usar strcpy()
        strcpy(memblock,file.c_str());

        paquetaxo.inicializaDatos( memblock, file.size() );
        socks.envia(paquetaxo);

        //la bandera ios:ate coloca el apuntador a archivo al final del archivo, esto permite conocer su
        //tamaño más rápidamente
        std::cout << "Abriendo: "<< path+file << "\n";
        std::ifstream origen( path+file, std::ios::binary | std::ios::ate );

        std::streampos pos = origen.tellg();//tellg() devuelve la posición en bytes del apuntador del objeto ifstream

        origen.seekg (0, std::ios::beg); //se regresa el apuntador de origen al inicio.

        //Dado un archivo de tamaño n, se divide en paquetes UDP. En teoría se debería poder soportar un
        //  tamaño de hasta 1500 bytes, pero en varias fuentes se recomienda dejar cierta holgura para cubrir
        //  diversas configuraciones de Ethernet.
        //Así mismo, un paquete muy pequeño puede encolar demasiadas llamadas en el servidor y provocar que
        //  el servidor no pueda procesar a tiempo los paquetes.
        //  Actualmente esta configuración funciona hasta para archivos de 2Mb antes de que el buffer del
        //  socket servidor se sature.
        int noPaquetes = (pos%1200==0) ? (pos/1200):(pos/1200)+1;
        std::cout << "Envienado "<< pos << "Bytes en "<< noPaquetes<< " Paquetes\n";

        ProSock::EnviarArchivo( socks, paquetaxo, origen, noPaquetes );
        // while( noPaquetes-- ){
        //     bzero( memblock, 1200 );
        //     origen.read( memblock, 1200 );
        //     //gcount() regresa los bytes leídos por read()
        //     paquetaxo.inicializaDatos( memblock, origen.gcount() );
        //     socks.envia(paquetaxo);
        //     //Debug: envia() regresa la cantidad de bytes que fueron enviados, puede utilizarse para extraer
        //     // información útil.
        // }
        origen.close();

        char end[] = "OKOKOKOKOKOKOK0000000000";
        bzero( memblock, 1200 );
        strcpy( memblock, end);
        paquetaxo.inicializaDatos( memblock, sizeof("OKOKOKOKOKOKOK0000000000") );
        socks.envia(paquetaxo);
    }

    void SolicitarPaquetes( std::string sendIP, int puerto, std::string file ){
        SocketBlob100 socks(0);
        PaqueteBlob100 paquetaxo(puerto);

        char IP[] = "127.0.0.1";

        strcpy( IP, sendIP.c_str() );
        paquetaxo.inicializaIP( IP );

        std::cout << "Enviando a: "<< IP <<":" << puerto << " el archivo "<< file << "\n";

        std::stringstream buff;
        //se debe asegurar que todos los buffers de salida se limpien con ceros para que todas las funciones
        //de escritura y lectura, funcionen correctamente.
        char memblock[1200];
        bzero( memblock, 1200 );
        int nBytes;
        int packs=0;

        //puesto que el nombre del archivo debe ser un texto, es correcto usar strcpy()
        strcpy( memblock, file.c_str() );

        paquetaxo.inicializaDatos( memblock, file.size() );
        socks.envia( paquetaxo );
        while( true ){
            nBytes = socks.recibe( paquetaxo );
            packs++;//Debug: sincroniza cantidad de paquetes recibidos

            char *aux = paquetaxo.obtieneDatos();//todo: optimizar ésto

            //si la cádena de fin tuviese que ser binaria, se debe cambiar este método.
            // De igual forma puede provocar errores para archivos binarios.
            if( strcmp( aux, ENDSTR ) == 0 ){
                break;
            }else{
                //Utilizar write() en objetos que decienden de std::ofstream nos permite guardar información
                //binaria
                buff.write(aux, nBytes);
            }
        }
        //Debug: buff.gcount devuelve la cantidad de caracteres extraídos, no la almacenada en buffer.
        std::cout << "Escribiendo: \n"<< file <<" de tamanio "<<buff.gcount()<< " recibido en "<< packs << " Paquetes\n";
        std::string path("temp/");
        path += file;
        std::ofstream destino( path,  std::ios::out | std::ios::binary);
        destino<<buff.rdbuf();
        destino.close();
    }

    void EnviarPaqueteSolicitado( int puerto ){
        SocketBlob100 servidor(puerto);
        PaqueteBlob100 paquetaxo(0);
        //Se necesita una cadena para avisar que un archivo termino de enviarse
        char end[] = "OKOKOKOKOKOKOK0000000000";

        //hilo princial
        while(true){
            int nBytes;
            int packs=0;
            char memblock[1200];
            //todo: separar cada intento de conexion a un hilo y asociar los buffers a una IP
            nBytes = servidor.recibe( paquetaxo );
            //std::stringstream no codifica texto, sino almacena streams de datos crudos.
            std::stringstream buff;
            //truckazo para concatenar char*
            std::string pt("espejo/");
            pt += paquetaxo.obtieneDatos();
            //la bandera std::ios:ate coloca el apuntador a archivo al final del archivo, esto permite conocer su
            //tamaño más rápidamente
            std::ifstream origen( pt, std::ios::binary | std::ios::ate );

            std::streampos pos = origen.tellg();//tellg() devuelve la posición en bytes del apuntador del objeto ifstream

            origen.seekg (0, std::ios::beg); //se regresa el apuntador de origen al inicio.

            //Dado un archivo de tamaño n, se divide en paquetes UDP. En teoría se debería poder soportar un
            //  tamaño de hasta 1500 bytes, pero en varias fuentes se recomienda dejar cierta holgura para cubrir
            //  diversas configuraciones de Ethernet.
            //Así mismo, un paquete muy pequeño puede encolar demasiadas llamadas en el servidor y provocar que
            //  el servidor no pueda procesar a tiempo los paquetes.
            //  Actualmente esta configuración funciona hasta para archivos de 2Mb antes de que el buffer del
            //  socket servidor se sature.
            int noPaquetes = (pos%1200==0) ? (pos/1200):(pos/1200)+1;
            std::cout << "Envienado "<< pos << "Bytes en "<< noPaquetes<< " Paquetes\n";

            while( noPaquetes-- ){
                bzero( memblock, 1200 );
                origen.read( memblock, 1200 );
                //gcount() regresa los bytes leídos por read()
                paquetaxo.inicializaDatos( memblock, origen.gcount() );
                servidor.envia(paquetaxo);
                //Debug: envia() regresa la cantidad de bytes que fueron enviados, puede utilizarse para extraer
                // información útil.
            }
            origen.close();

            bzero( memblock, 1200 );
            strcpy( memblock, end);
            paquetaxo.inicializaDatos( memblock, sizeof("OKOKOKOKOKOKOK0000000000") );
            servidor.envia(paquetaxo);
        }
    }

}


#endif
