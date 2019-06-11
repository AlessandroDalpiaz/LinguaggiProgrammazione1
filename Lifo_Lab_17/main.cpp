#include "dati.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	Tnodo *n=NULL;
	stampa(n);
	Tdato d;
	Tdato d2;
	d.cognome="Rossi";
	d.nome="Lorenzo";
	d.eta=10;
	n=push(n,d);
	
	d2.cognome="Verdi";
	d2.nome="Giuseppe";
	d2.eta=150;
	n=push(n,d2);
	printf("-----stampa i push-------\n");
	stampa(n);
	printf("---------------- %d\n",length(n));
	printf("-----stampa il pop-------\n");
	n=pop(n);
	d=read(n);
	stampa(n);
	printf("-----stampa il read-------\n");
	d.stampa();
	if(daticmp(d,d2))
	{
		printf("TRUE\n");
	}else printf("FALSE\n");
	return 0;
}
