#include <iostream>
#include <cstdlib>
#include "dati.h"

using namespace std;

int main(int argc, char** argv) {
	TipoStack mios(5); //struttura nella memoria STACK
	TipoStack* pmios; //puntatore nella memoria STACK
	pmios = new TipoStack(8); //allocazione nella momeoria HEAP
	Tdato d(9,8,7);
	pmios->stampa();
	pmios->push(Tdato());
	pmios->push(Tdato(4,3,2));
	pmios->push(d);
	pmios->stampa();
	if(!pmios->isEmpty()){
		d = pmios->pop();
		pmios->stampa();
	}
	delete pmios;
	
	return 0;
}
