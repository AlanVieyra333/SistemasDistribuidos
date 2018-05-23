run: compile
compile: PaqueteDatagrama.o SocketDatagrama.o
	g++ servidor.cpp PaqueteDatagrama.cpp SocketDatagrama.cpp -o servidor
PaqueteDatagrama.o:
	g++ -c PaqueteDatagrama.cpp
SocketDatagrama.o:
	g++ -c SocketDatagrama.cpp
clean:
	rm PaqueteDatagrama.o
	rm SocketDatagrama.o
	rm c
	rm s
