#include <iostream>
#include "dati.h"

int main(int argc, char** argv) {
	
	Nodoptr s;
	Tdato d;
	d=Tdato(1,1.1);
	
	printf("Insert first\n");
	s= insertFirst(s,d);
	s->stampa();
	printf("\nInsert first\n");
	s= insertFirst(s,Tdato(2,2.2));
	s= insertLast(s,Tdato(2,2.2));
	s->stampa();
	
	return 0;
}
