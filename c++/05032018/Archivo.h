#ifndef COORDENADA_H_
#define COORDENADA_H_
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <cwchar>
#include <fcntl.h>

using namespace std;

class Archivo{
	private:
		string nombreArchivo;
		int fd;
		char *contenido;
		size_t num_bytes = 0;
		mode_t mod;

	public:
		Archivo(string filename);
		Archivo(string filename, int banderas, mode_t modo);
		size_t lee(size_t nbytes);
		size_t escribe(void *buffer, size_t nbytes);
		size_t obtieneNum_bytes();
		const char *get_contenido();
		~Archivo();
};

#endif
