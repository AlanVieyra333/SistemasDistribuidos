#ifndef __SOCKETDATAGRAMA_H__
#define __SOCKETDATAGRAMA_H__

#include "PaqueteDatagrama.h"
#include <netinet/in.h>

class SocketDatagrama{
	public:

		SocketDatagrama(int);
		~SocketDatagrama();
		//Recibe un paquete tipo datagrama proveniente de este socket
		int recibe(PaqueteDatagrama *p);
		//Envía un paquete tipo datagrama desde este socket
		int envia(PaqueteDatagrama *p);
		
	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int _s; //ID socket
};

#endif