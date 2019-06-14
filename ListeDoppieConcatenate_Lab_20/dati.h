#ifndef __dati_h__
#define __dati_h__


#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#define EPS 0.001
typedef struct Tdato{
	int index;
	float value;
	Tdato(){
	}
	Tdato(int i,float f){
		index=i;
		value= f;
	}
	~Tdato(){}
    void stampa(){
      printf(" [%d-%f] ",index,value);
    } 	
    bool gt(Tdato d){
      return (value > d.value);
    }
	bool eq(Tdato d){
		return (value > d.value-EPS && value < d.value+EPS);
	}
}Tdato;
typedef Tdato Dato;

typedef struct Tnodo{
	Dato dato;
	Tnodo* prev;
	Tnodo* next;
  	Tnodo(Tdato d){ 
		dato=d; prev=NULL; next=NULL; 
  	}
  	Tnodo(Tdato d, Tnodo* p,  Tnodo* n){ 
    	dato=d; prev=p; next=n;
  	}
  	void stampa(){ 
    	dato.stampa(); 
  	}
}Tnodo;

typedef Tnodo Nodo;
typedef Tnodo* Nodoptr;

Nodoptr insertFirst(Nodoptr s,Dato d);
Nodoptr insertLast(Nodoptr s, Tdato d);

Nodoptr insertFirst(Nodoptr s,Dato d){
	Nodoptr t = new Nodo(d, NULL, s); // creo il nodo con il nuovo dato
	if(s == NULL){	// verifico se la coda è vuota
		s->prev = t; 	// inserimento al primo posto
    }
	return t;
}

Nodoptr insertLast(Nodoptr s, Tdato d){
    if (s == NULL) {
		s = insertFirst(s, d);
		return s;
	}
	Nodoptr p = s;
	while (p->next != NULL) { //scorro fino all'ultimo
		p = p->next;
	}
	p->next = new Nodo(d, p, NULL);
	return s;
}




#endif
