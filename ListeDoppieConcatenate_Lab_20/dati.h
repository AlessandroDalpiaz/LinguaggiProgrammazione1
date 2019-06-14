#ifndef DATI_H_
#define DATI_H_
#include <cstdlib>
#include <iostream>
using namespace std;

// the main structure
typedef struct Tipodata {
    unsigned int posizione;
    char* contenuto;
    Tipodata(){
		posizione=0;
		contenuto=NULL;
	}  
    Tipodata(unsigned int p, char* c){
		posizione=p;
		contenuto=c; }
    void stampa(){
		cout << "["<<posizione<<":'"<<contenuto<<"']";
	} 	
	bool gt(Tipodata d){
  		if (posizione>d.posizione){
		  	return true;
		}else {
			return false;	
		}
	}
}Tipodata;

typedef struct Tiponodo {
  	Tipodata dato;
  	Tiponodo* prev;  
  	Tiponodo* next;
  	Tiponodo(){
	Tipodata d; dato=d; prev=NULL; next=NULL;
	}
  	Tiponodo(Tipodata d, Tiponodo* p,  Tiponodo* n){
	  	dato=d; prev=p; next=n;
	}
  	void stampa(){
	  	dato.stampa();
	}	
}Tiponodo;
typedef Tipodata dati;
typedef Tiponodo nodo;
typedef Tiponodo* nodoPtr;

// function prototypes
int lung(nodoPtr s);
nodoPtr insertLast(nodoPtr s,dati CurrD);
nodoPtr insertFirst(nodoPtr s, dati CurrD);
nodoPtr insertOrder(nodoPtr s, dati CurrD);
void stampa(nodoPtr s);
nodoPtr removeFirst(nodoPtr s);
nodoPtr removeLast(nodoPtr s);
nodoPtr put(nodoPtr s, dati CurrD);
nodoPtr get(nodoPtr s);
dati readFirst(nodoPtr s);


#endif

