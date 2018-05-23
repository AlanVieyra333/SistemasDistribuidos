#include "PaqueteDatagrama.h"
#include <cstring>
#include <cstdlib>

PaqueteDatagrama::PaqueteDatagrama(char * dat, unsigned int size, char * ipDir, int port)
{
	longitud=size;
	datos=new char[longitud];
	memcpy(datos, dat, longitud);
	memcpy(ip,ipDir,16);
	puerto=port;
}


PaqueteDatagrama::~PaqueteDatagrama()
{
	delete(datos);
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int size)

{
	longitud=size;
	datos = new char[longitud];
}

char * PaqueteDatagrama::obtieneDireccion()
{
	return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud()
{
	return longitud;
}

int PaqueteDatagrama::obtienePuerto()
{
	return puerto;
}

char *PaqueteDatagrama::obtieneDatos()
{
	return datos;
}

void PaqueteDatagrama::inicializaPuerto(int port)
{
	puerto = port;
}

void PaqueteDatagrama::inicializaIp(char * ipDir)
{
	memcpy(ip,ipDir,16);	
}

void PaqueteDatagrama::inicializaDatos(char * data)
{
	memcpy(datos,data,longitud);
}



