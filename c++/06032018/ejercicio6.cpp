#include <unistd.h>	// sleep
#include <thread>
#include "Semaforo.h"

using namespace std;

int x = 0;
Semaforo semaforo1, semaforo2;

void incre(int n){
	semaforo1.wait();
	while (n >= 0){
		x++;
		sleep(1);
		n--;
	}
	semaforo2.post();
}

void decre(int n){
	semaforo2.wait();
	while (n >= 0){
		x--;
		sleep(1);
		n--;
	}
	semaforo1.post();
}

int main(){
	int nVeces = 50;
	semaforo1.init(1);
	semaforo2.init(0);

	thread th1(incre, nVeces), th2(decre, nVeces);
	

	th1.join();
	th2.join();
	printf("La variable global tiene un valor de: %d\n", x);
	exit(0);
}
