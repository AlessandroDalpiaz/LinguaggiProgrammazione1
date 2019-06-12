#include "dati.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#define MAX 20
#define K 15
#define N 3

int casuale(int min ,int max){
	return rand()%(max-min+1)+min;
}
//inserisce x in coda
CodaPtr put (CodaPtr p, Tdato d){
	CodaPtr n;
	n=p;
	Tnodo* q=new Tnodo(d,NULL); // NUOVO ELEMENTO
	if(n->tail==NULL){			//lista vuota
		n->head = q;
	}else{
		n->tail->next=q;
	}
	n->tail=q; //assegno come ultimo nodo
	p=n;
	return p;
}

//estrae l’elemento in testa alla lista
Tdato get (CodaPtr p){
	Tdato d; //invoco costruttore di default
	if(p->head==NULL){ //lista vuota
		return d;
	}
	d=p->head->dato;
	//caso 1 solo nodo
	if (p->head->next==NULL) {
		delete p->head;
		p->head=NULL; p->tail=NULL;
	} else {
		Tnodo* s= p->head;
		p->head = p->head->next;
		delete s;
	}
	return d;
}
//inteoria legge il'ultimo elemento inserito
Tdato read(CodaPtr p){
	Tdato d;
	if(p->head!=NULL){
		d=p->head->dato;
	}
	return d;
}
