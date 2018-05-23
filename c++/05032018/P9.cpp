// g++ P9.cpp Archivo.cpp -o P9 && ./P9 img1.jpg img2.jpg
#include "Archivo.h"

int main (int argc, char *argv[]) {
  int nbytes = 0;

  if(argc != 3) {
     printf("Forma de uso: %s archivo_origen archivo_destino\n", argv[0]);
     exit(-1);
  }

  Archivo archivo_origen(argv[1]);
  Archivo archivo_destino(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0666);

  while((nbytes = archivo_origen.lee(BUFSIZ)) > 0);

  archivo_destino.escribe((char *) archivo_origen.get_contenido(), archivo_origen.obtieneNum_bytes());

	return 0;
}
