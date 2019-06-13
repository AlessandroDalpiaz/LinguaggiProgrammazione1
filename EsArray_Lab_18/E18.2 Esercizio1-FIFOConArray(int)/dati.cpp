#include <iostream>
#include "dati.h"

#define N_ELEM 5


bool CodaIsEmpty(CodaPtr p){
	//if(dim==head==tail==0){
	if(p->n==0){
		return true;
	}else return false;
}
bool CodaIsFull(CodaPtr p){
	if(p->n==p->dim){
		return true;
	}else{
		return false;
	}
	//return (p->n == p->dim)
}
void Put(CodaPtr p, int x){
	if (CodaIsFull(p)) {
		cout << "Coda piena, " << x << " non iserito" << endl;
	}
	else {
		p->n++;
		p->s[p->tail] = x;
		p->tail = (p->tail + 1) % (p->dim);
	}
}
int Get(CodaPtr p){//RIMUOVE
	if (CodaIsEmpty(p)) {
		cout << "Coda vuota, " << endl;
	}
	else{
		int r = p->s[p->head];//prendo in posizione head
		p->n--;
		p->head= p->head+1;//sposto head de uno
		p->head = p->head % p->dim;
		return r;
	}
}

// Stampa il contenuto della coda
void Print(CodaPtr p){
	int i;
	if (CodaIsEmpty(p)) {
		cout << "La coda e' vuota" << endl;
		return;
	}
	//cout << "Testa:" << p->head  << " Coda:" << p->tail <<  endl;
	i=p->head;
	// cout <<"[" << p->s[i] << "]"; 
	do{
		//cout <<"[" << p->s[i] << "]"; 
		cout << i << "->[" << p->s[i] << "] ";
		i=++i % (p->dim);
	}while (i!=p->tail);
}
