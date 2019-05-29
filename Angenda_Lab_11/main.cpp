#include "dati.h"
#include <iostream>
#define MAX_EVENTI 10

int main(int argc, char** argv) {
	Tdata d1, d2;
	Tevento e;
	Tagenda a;
	
	d1 = inizializzaData(2009,6,10,10,30);
	d2 = inizializzaData(2009,6,10,11,30);
	e = inizializzaEvento(d1,d2,PISCINA);
	a.addEvento(e);
	d1 = inizializzaData(2009,6,11,14,30);
	d2 = inizializzaData(2009,6,11,16,0);
	e = inizializzaEvento(d1,d2,STUDIO);
	a.addEvento(e);
	d1 = inizializzaData(2009,7,11,16,0);
	d2 = inizializzaData(2009,6,11,16,30);
	e = inizializzaEvento(d1,d2,APPUNTAMENTO);
	a.addEvento(e);
	a.stampa();
	char *nome="Agenda.txt";
	printf("%d",a.scriviFile(nome));
	return 0;
}
