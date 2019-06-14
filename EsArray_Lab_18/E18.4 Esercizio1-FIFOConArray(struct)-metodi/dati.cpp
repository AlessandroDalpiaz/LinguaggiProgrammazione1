#include <iostream>
#include "dati.h"

bool codaIsEmpty(CodaPtr p){
	if(p->n==0){
		return true;
	}else return false;
}
bool codaIsFull(CodaPtr p){
	if(p->n==p->dim){
		return true;
	}else return false;
}
void put(CodaPtr p, Tdato d){
	if(codaIsFull(p)){
		printf("Coda piena\n");
	}else{
		p->n++;
		p->s[p->tail]=d;
		p->tail++; //array va da 0 a dim-1
		p->tail=p->tail%p->dim;
	}
}
Tdato get(CodaPtr p){
	Tdato d;
	d=p->s[p->head];
	p->head++;
	p->n--;
	p->head=p->head%p->dim;
	return d;
}
void stampa(CodaPtr p){
	p->stampa();
}



