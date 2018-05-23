#include "SocketDatagrama.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>

SocketDatagrama::SocketDatagrama(int port)
{
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	_s = socket(AF_INET, SOCK_DGRAM, 0);
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(port);
	bind(_s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));
}

SocketDatagrama::SocketDatagrama(int port, char * address)
{
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	_s = socket(AF_INET, SOCK_DGRAM, 0);
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = inet_addr(address);
	direccionLocal.sin_port = htons(port);
	bind(_s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));
}

SocketDatagrama::SocketDatagrama()
{
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	_s = socket(AF_INET, SOCK_DGRAM, 0);
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(0);
	bind(_s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama()
{
	shutdown(_s, 2);
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

void SocketDatagrama::setReusePort(bool reuse)
{
	int r = reuse ? 1 : 0;
	setsockopt(_s, SOL_SOCKET, SO_REUSEPORT, &r,sizeof(int));
}