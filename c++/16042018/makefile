all: servidor cliente
	@echo "Compílados."

servidor: servidor.cpp
	g++ PaqueteDatagrama.cpp SocketDatagrama.cpp servidor.cpp -o servidor

cliente: cliente.cpp
	g++ PaqueteDatagrama.cpp SocketDatagrama.cpp cliente.cpp -o cliente
