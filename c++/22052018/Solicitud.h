#include <SocketDatagrama.h>

class Solicitud {
public:
  Solicitud();
  char * doOperation(char *IP, int puerto, int operationId, char *arguments);
private:
  SocketDatagrama *socketlocal;
};
