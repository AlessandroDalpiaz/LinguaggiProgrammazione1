#include <iostream>
#include "dati.h"

#define NELEM 5
using namespace std;

int main(int argc, char** argv) {
		
	CodaPtr c2=new Coda(NELEM);
	printf("inserisco elemento\n");
	c2->Put(Tdato(1));
	printf("stampa\n");
	c2->Stampa();
	printf("\ninserisco elemento\n");
	c2->Put(Tdato(2));
	printf("inserisco elemento\n");
	c2->Put(Tdato(3));
	printf("stampa\n");
	c2->Stampa();
	printf("\nget()\n");
	c2->get();
	printf("stampa\n");
	c2->Stampa();
	
	return 0;
	
}
