#include <iostream>

using namespace std;

const double PI=3.1415926;

int main(){

	double radio, area;
	//PI=3;
	/*	Ejercicio1.cpp:10:4: error: assignment of read-only variable 'PI'
  			PI=3;
    			^
		Ejercicio1.cpp:10:6: error: expected ';' before ':' token
  			PI=3:
      			^
     */

	cout<<"Ingrese el radio: ";
	cin>>radio;
	area=PI*(radio*radio);
	cout<<"\n El area es:" <<area << "\n";

}
