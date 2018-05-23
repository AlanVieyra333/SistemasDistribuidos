#include <iostream>
#include <unistd.h>
#include <thread>
#include <sstream>
#include <atomic>

using namespace std;

void incre(int n, atomic<int>& var){
	while (n >= 0){
		var++;
		sleep(1);
		n--;
	}
}

void decre(int n, atomic<int>& var){
	while (n >= 0){
		var--;
		sleep(1);
		n--;
	}
}

int main(){
	atomic<int> x(0);
	int nVeces = 50;
	thread th1(incre, nVeces, ref(x)), th2(decre, nVeces, ref(x));
	th1.join();
	th2.join();
	printf("La variable global tiene un valor de:");
	cout << x << endl;
	exit(0);
}

