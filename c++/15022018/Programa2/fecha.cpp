#include "fecha.h" 
#include <iostream> 

using namespace std; 
 
Fecha::Fecha(int dd, int mm, int aaaa) 

{

    mes = mm;   
    dia = dd;    
    anio = aaaa; 
}

void Fecha::inicializaFecha(int dd,int mm, int aaaa){


	anio=aaaa;
	mes=mm;
	dia=dd;
	return;
}

void Fecha::muestraFecha()
{
	cout<<"La fecha es(dia-mes-anio): " <<dia <<"-" <<mes <<"-" <<anio << endl;
	return;
}
