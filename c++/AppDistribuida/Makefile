.PHONY: all
all: run

server: server.cpp PaqueteDatagrama SocketDatagrama gfx Point
	g++ -I./lib gfx -lX11 -pthread PaqueteDatagrama SocketDatagrama Point server.cpp -o server

PaqueteDatagrama: lib/PaqueteDatagrama.cpp
	g++ -I./lib lib/PaqueteDatagrama.cpp -c -o PaqueteDatagrama

SocketDatagrama: lib/SocketDatagrama.cpp
	g++ -I./lib lib/SocketDatagrama.cpp -c -o SocketDatagrama

Point: lib/Point.cpp
	g++ -I./lib lib/Point.cpp -c -o Point

gfx: lib/gfx.c
	gcc lib/gfx.c -c -o gfx

.PHONY: run
run: server
	./server 7000
