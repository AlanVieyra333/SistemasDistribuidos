sendPalabras: sendPalabras.cpp Sockett/Protocolos.hpp Sockett/SocketT.hpp Sockett/Paquete.hpp
	g++ -std=c++11 -lm sendPalabras.cpp Sockett/Protocolos.hpp Sockett/SocketT.hpp Sockett/Paquete.hpp -o sendPalabras -lpthread

CachaPalabras: CachaPalabras.cpp Sockett/Protocolos.hpp Sockett/SocketT.hpp Sockett/Paquete.hpp
	g++ -std=c++11 -lm CachaPalabras.cpp Sockett/Protocolos.hpp Sockett/SocketT.hpp Sockett/Paquete.hpp -o CachaPalabras -lpthread

clean:
	rm sendPalabras Proxy CachaPalabras ServidorEspejo Espejo EspejoCarga
	rm Sockett/*.gch
