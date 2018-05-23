#include "Fecha.h"
#include <iostream>

using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa) {
 mes = mm;
 dia = dd;
 anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa) {
 anio = aaaa;
 mes = mm;
 dia = dd;
 return;
}

void Fecha::muestraFecha() {
 cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
 return;
}

int Fecha::convierte(){
  return anio*10000 + mes*100 + dia;
}

bool Fecha::leapyr(){
  float div1 = (float)anio/4;
  int div2 =anio/4;
  float res1 = div1-div2;

  float div3 = (float)anio/100;
  int div4 =anio/100;
  float res2 = div3-div4;

  if(res1 == 0){
    if(!(res2==0)){
      cout << "Es un año bisiesto" << endl;
      return true;
    }
    else if(anio % 400 == 0){
      cout << "Es un año bisiesto" << endl;
      return true;
    }else{
      cout << "No es un año bisiesto" << endl;
    }
  }
  else cout << "No es un año bisiesto" << endl;

  return false;
}
