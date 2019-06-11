#include "dati.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Nodoptr push (Nodoptr p, Tdato d){
	if(p==NULL){
		return new Tnodo(d);
	}
	return new Tnodo(d,p);
}
Nodoptr pop (Nodoptr p){
	if(p==NULL){
		return p;
	}
	Nodoptr q=p->next;
	delete p;
	return q;
}
Tdato read (Nodoptr n){
	if(n==NULL){
		printf("lista vuota\n");
		return Tdato();
	}
	return n->dato;
	
}
bool daticmp (Tdato d1, Tdato d2){
	if(strcmp(d1.cognome,d2.cognome)==0 &&strcmp(d1.nome,d2.nome)==0 && d1.eta==d2.eta){
		return true;
	}else return false;
}
int length (Nodoptr p){
	if(p==NULL){
		return 0;
	}
	int tmp;
	Nodoptr q=p;
	while(q->next!=NULL){
		tmp++;
		q=q->next;
	}
	if(q->next==NULL){
		tmp++;
	}
	return tmp;
}
void stampa(Nodoptr n){
	if(n==NULL){
		printf("lista vuota\n");
		return;
	}
	Nodoptr h=n;
	while (h->next!=NULL){ //cerco il puntatore prossimo disponibile, ovvero =NULL
		h->stampa();
		h=h->next;	
	}
	if(h->next==NULL){
		h->stampa();
	}
}
