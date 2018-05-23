#include "Archivo.h"
#include <unistd.h>

//lectura
Archivo::Archivo(string filename) {
	nombreArchivo = filename;
	fd = open(nombreArchivo.c_str(), O_RDONLY);

  if (fd == -1) {
    perror(filename.c_str());
    exit(-1);
  }

	contenido = (char*)malloc(sizeof(char) * 1);
}

//escritura
Archivo::Archivo(string filename, int banderas, mode_t modo) {
	nombreArchivo = filename;
	fd = open(nombreArchivo.c_str(), banderas, modo);

  if (fd == -1) {
    perror(filename.c_str());
    exit(-1);
  }

	contenido = (char*)malloc(sizeof(char) * 1);
}

Archivo::~Archivo() {
  free(contenido);
  close(fd);
}
/*///////////////////////////////////////////////////////////////////////*/

size_t Archivo::lee(size_t nbytes) {
  // Reasignar memoria.
  contenido = (char *)realloc(contenido, num_bytes + nbytes);
  size_t current_num_bytes = read(fd, contenido + num_bytes, nbytes);
	num_bytes += current_num_bytes;
  
	return current_num_bytes;
}

size_t Archivo::escribe(void *buffer, size_t nbytes) {
  return write(fd, buffer, nbytes);
}

size_t Archivo::obtieneNum_bytes() {
	return num_bytes;
}

const char * Archivo::get_contenido(){
	const char *a = contenido;

	return a;
}
