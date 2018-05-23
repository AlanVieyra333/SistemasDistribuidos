#include <iostream>
#include <unistd.h>
#include <thread>
#include "Semaforo.h"
#define n 10

using namespace std;

int global = 3;
Semaforo sem1, sem2, sem3;

void funcion1(){
	bool ok = true;
	while(global){
		sem1.wait();
		if(ok){
			ok = false;
			printf("Soy el hilo 1, y esta es la impresion %d\n", global-- );
		}
		sem2.post();
	}
	//sem2.post();
}

void funcion2(){
	bool ok = true;
	while(global){
		sem2.wait();
		if(ok){
			ok = false;
			printf("Soy el hilo 2, y esta es la impresion %d\n", global-- );
		}
		
		sem3.post();
	}
}

void funcion3(){
	bool ok = true;
	while(global){
		sem3.wait();
		if(ok){
			ok = false;
			printf("Soy el hilo 3, y esta es la impresion %d\n", global-- );
		}
		
		sem1.post();
	}
}

int main(){
//Inicializa los semaforos
	sem1.init(1);
	sem2.init(0);
	sem3.init(0);
	thread th1(funcion1), th2(funcion2), th3(funcion3);
	th1.join();
	th2.join();
	th3.join();
	exit(0);
}
