#include <iostream>
#include <unistd.h>
#include <thread>
#include <sstream>

using namespace std;

int x = 0;

void incre(int valor){
	while (valor >= 0){
		x++;
		sleep(1);
		valor--;
	}
}

void decre(int valor){
	while (valor >= 0){
		x--;
		sleep(1);
		valor--;
	}
}

int main(){
	thread th1(incre, 5), th2(decre, 5);
	th1.join();
	th2.join();
	printf("La variable global tiene un valor de: %d\n", x);
	exit(0);
}
