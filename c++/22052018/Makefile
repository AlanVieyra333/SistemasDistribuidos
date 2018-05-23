.PHONY: all
all: run

server: server.cpp PaqueteDatagrama SocketDatagrama
	g++ -I./lib PaqueteDatagrama SocketDatagrama server.cpp -o server

client: client.cpp PaqueteDatagrama SocketDatagrama
	g++ -I./lib PaqueteDatagrama SocketDatagrama client.cpp -o client

PaqueteDatagrama: ../lib/PaqueteDatagrama.cpp
	g++ -I../lib ../lib/PaqueteDatagrama.cpp -c -o PaqueteDatagrama

SocketDatagrama: ../lib/SocketDatagrama.cpp
	g++ -I../lib ../lib/SocketDatagrama.cpp -c -o SocketDatagrama

.PHONY: run
run: server client
	@echo "Compilado."
	@echo "Ejecuta:"
	@echo "./server <length_in_pixels>"
	@echo "./client <speed_in_pixels>"
