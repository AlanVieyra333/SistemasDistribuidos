#ifndef __PAQUETEDATAGRAMA_H__
#define __PAQUETEDATAGRAMA_H__

class PaqueteDatagrama {
	public:
    PaqueteDatagrama();
		PaqueteDatagrama(char * datos, unsigned int longitud, char * ip, int puerto);
		PaqueteDatagrama(unsigned int longitud);
		~PaqueteDatagrama();
		char *obtieneDireccion();
		unsigned int obtieneLongitud();
		int obtienePuerto();
		char *obtieneDatos();
		void inicializaPuerto(int);
		void inicializaIp(char *);
	private:
		char * _datos;
		//Almacena los datos
		char _ip[16];
		//Almacena la IP
		unsigned int _longitud;
		//Almacena la longitude de la cadena de datos
		int _puerto;
		//Almacena el puerto
};

#endif
