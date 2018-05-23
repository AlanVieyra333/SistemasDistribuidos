#include <iostream>
#include <unistd.h>
#include <thread>
#include <sstream>

using namespace std;

int x = 0;

void incre(int n){
	while (n >= 0){
		x++;
		sleep(1);
		n--;
	}
}

void decre(int n){
	while (n >= 0){
		x--;
		sleep(1);
		n--;
	}
}

int main(){
	int nVeces = 50;
	thread th1(incre, nVeces), th2(decre, nVeces);
	th1.join();
	th2.join();
	printf("La variable global tiene un valor de: %d\n", x);
	exit(0);
}
