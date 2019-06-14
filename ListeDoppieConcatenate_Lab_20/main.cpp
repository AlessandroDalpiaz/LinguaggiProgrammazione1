#include <cstdlib>
#include <iostream>
#include "dati.h"
#include <string.h>
int main(int argc, char** argv) {
	
	Tipodata d;
	nodoPtr p=NULL; //lista vuota
	d=Tipodata(1,"aaa");

	p=put(p,d);  //p=insertLast(p,d);
	stampa(p);
	p=put(p,Tipodata(2,"bbb"));
	p=put(p,Tipodata(3,"ccc"));
	p=put(p,Tipodata(4,"ddd"));
	stampa(p);
	printf("\n--------------------------------\n");
	printf("REMOVE FIRST\n");
	p=get(p);//RemoveFirst
	stampa(p);
	printf("\n--------------------------------\n");
	printf("REMOVE LAST\n");
	p=removeLast(p);
	stampa(p);
	printf("\n--------------------------------\n");
	printf("INSERT ORDER 10\n");
	p=insertOrder(p,Tipodata(10,"ddd"));
	stampa(p);
	printf("\n--------------------------------\n");
	printf("lunghezza\n");
	printf("%d\n",lung(p));
	printf("\n--------------------------------\n");
	printf("READ FIRST\n");
	dati l;
	l=readFirst(p);
	l.stampa();
	printf("\n--------------------------------\n");
	stampa(p);
	
	
	return 0;
}
