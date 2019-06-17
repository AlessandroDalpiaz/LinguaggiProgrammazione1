#include <iostream>
#include <stdlib.h>
#include "dati.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	TcodaFIFO* p = new TcodaFIFO(10);
	
	Tveicolo v;
	for(int i=0; i<2; i++) {
		creaVeicolo(&v);
		addVeicolo(p,v);
	}
	stampaVeicolo(p);
	
	delAuto(p, 2000);
	
	return 0;
}
