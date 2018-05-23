/* Archivo rand.x */

struct datos {
  double a;
  double b;
  double r;
  char message[100];
};

program RAND_PROG {
   version RAND_VERS {
      datos SUMA(datos) = 1;
      datos PRODUCTO(datos) = 2;
      datos COCIENTE(datos) = 3;
   } = 1;
} = 0x31111111;
