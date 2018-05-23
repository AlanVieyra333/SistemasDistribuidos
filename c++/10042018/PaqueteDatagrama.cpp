#include "PaqueteDatagrama.h"

PaqueteDatagrama::PaqueteDatagrama(char* datos_, unsigned int longitud_, char* ip_, int puerto_) {
  datos = new char[longitud_];
  memcpy(datos, datos_, sizeof(char) * longitud_);
  longitud = longitud_;
  strcpy(ip, ip_);
  puerto = puerto_;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitud_) {
  datos = new char[longitud_];
  longitud = longitud_;
}

PaqueteDatagrama::~PaqueteDatagrama() {
  delete[] datos;
}

char* PaqueteDatagrama::obtieneDireccion() {
  return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud() {
  return longitud;
}

int PaqueteDatagrama::obtienePuerto() {
  return puerto;
}

char* PaqueteDatagrama::obtieneDatos() {
 return datos;
}

void PaqueteDatagrama::inicializaPuerto(int puerto_) {
  puerto = puerto_;
}

void PaqueteDatagrama::inicializaIp(char* ip_) {
  strcpy(ip, ip_);
}

void PaqueteDatagrama::inicializaDatos(char* datos_) {
  datos = datos_;
}
