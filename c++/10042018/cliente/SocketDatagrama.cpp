#include "SocketDatagrama.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

SocketDatagrama::SocketDatagrama(int port)
{
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	_s = socket(AF_INET, SOCK_DGRAM, 0);
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(port);
	bind(_s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));
}


SocketDatagrama::~SocketDatagrama()
{
	close(_s);
}


int SocketDatagrama::recibe(PaqueteDatagrama *p)
{
	unsigned int addr_len = sizeof(direccionForanea);
	int answer = recvfrom(_s, p->obtieneDatos(), p->obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &addr_len);
	p->inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	p->inicializaPuerto(ntohs(direccionForanea.sin_port));
	return answer;
}

int SocketDatagrama::envia(PaqueteDatagrama *p)
{
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p->obtieneDireccion());
	direccionForanea.sin_port = htons(p->obtienePuerto());
	sendto(_s, p->obtieneDatos(), p->obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}



