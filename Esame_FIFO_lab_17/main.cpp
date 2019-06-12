#include "dati.h"
#include <iostream>
#include <stdlib.h>

int main(int argc, char** argv) {
	TcodaFIFO* p[3] = {NULL, NULL, NULL};
	Tspedizione s;
	for(int i=0; i<5; i++) {
		creaSpedizione(&s);
		addPacco(p,s);
	}
	
	stampaSpedizioni(p);
	delPacchi(p, ORDINARIO);
	return 0;
}
