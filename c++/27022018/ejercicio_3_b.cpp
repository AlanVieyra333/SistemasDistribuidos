#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string>

using namespace std;

char cadenota[17576 * 15]="";
int j = 0, count = 0;

void generateStr(int n) {
  for (int i = 0; i < n; i++) {
    char char1 = (rand() % 26) + 65;
    char char2 = (rand() % 26) + 65;
    char char3 = (rand() % 26) + 65;

  	cadenota[j] = char1;
  	j++;
  	cadenota[j] = char2;
  	j++;
  	cadenota[j] = char3;
  	j++;
  }
}

void searchWord(char a, char b, char c) {
  int x = 0;
  while (x < j-2) {
	if (cadenota[x] == a)
	  if (cadenota[x+1] == b)
		if (cadenota[x+2] == c)
		  count++;
	x++;
  }
}

int main() {
  srand (time(NULL));
  
  generateStr(17576*15);
  searchWord('I','P','N');
  cout << "Ocurrencias: " << count << endl;
  return 0;
}
