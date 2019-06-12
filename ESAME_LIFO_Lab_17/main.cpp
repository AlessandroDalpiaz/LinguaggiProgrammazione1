#include "dati.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	Telem tele;
	Tbiglietto biglietto;
	Tbiglietteria biglietteria;
	for(int i=0;i<20;i++){
		creaBiglietto(&biglietto);
		inserisciBiglietto(&biglietteria,biglietto);
	}
	biglietteria.stampa();
	tele= cercaMezzo(biglietteria);
	StampaMezzo(tele.mezzo);
	printf(" %f",tele.n/biglietteria.numBiglietti);
	return 0;
}
