#include <iostream>
#include "fifo.h"

#define NELEM 5
using namespace std;

int main(int argc, char** argv) {
		
	CodaPtr c1 = new Coda(NELEM);
	cout << "La coda e' vuota? " << codaIsEmpty(c1) << endl;
	cout << "La coda e' piena? " << codaIsFull(c1) << endl;
	cout << "Contenuto della coda:" << endl; 
	stampa(c1);
	printf("\n"); 
	cout << "Put 1, ora la coda contiene:" << endl;
	put(c1, Tdato(1));  
	stampa(c1);
	printf("\n"); 
	cout << "Put 2, 3, 4, 5; ora la coda contiene:" << endl;
	put(c1, Tdato(2)); 
	put(c1, Tdato(3)); 
	put(c1, Tdato(4)); 
	put(c1, Tdato(5));  
	stampa(c1);
	printf("\n"); 
	cout << "Put 6, ora la coda contiene:" << endl;
	put(c1, Tdato(6)); //non viene inserito: coda piena
	stampa(c1);
	printf("\n"); 
	printf("Get(C1):"); 	
	get(c1).stampa();
	printf("\n");
	cout << "GET, ora la coda contiene:" << endl; 
	stampa(c1);
	return 0;
}
