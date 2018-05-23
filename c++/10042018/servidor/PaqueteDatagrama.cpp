#include "PaqueteDatagrama.h"
#include <cstring>
#include <cstdlib>

PaqueteDatagrama::PaqueteDatagrama(char * datos, unsigned int longitud, char * ip, int puerto)
	: _longitud(longitud), _puerto(puerto)
{
	_datos = (char*)malloc(longitud * sizeof(char));
	memcpy( _datos, datos, longitud);
	strcpy (_ip,ip);
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitud)
	: _longitud(longitud)
{
	_datos = (char*)malloc(longitud * sizeof(char));
}

char * PaqueteDatagrama::obtieneDireccion()
{
	return _ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud()
{
	return _longitud;
}

int PaqueteDatagrama::obtienePuerto()
{
	return _puerto;
}

char *PaqueteDatagrama::obtieneDatos()
{
	return _datos;
}

void PaqueteDatagrama::inicializaPuerto(int puerto)
{
	_puerto = puerto;
}

void PaqueteDatagrama::inicializaIp(char * ip)
{
	strcpy (_ip,ip);	
}

PaqueteDatagrama::~PaqueteDatagrama()
{
	free(_datos);
}