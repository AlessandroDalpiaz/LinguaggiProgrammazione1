#include <iostream>
#include <cstring>
using namespace std;

#ifndef __TREE__
#define __TREE__

#define MAXL 30

typedef struct Tdato{
	int eta;
	char nome[MAXL];
	Tdato(){
		eta =0;
		nome[0]='\0';
	}
	Tdato(int _eta){
		eta = _eta;
		nome[0]='\0';
	}
	Tdato(int _eta, char* _nome){
		eta = _eta;
		strcpy(nome, _nome);
	}
	void stampa(){
		cout << "[" << nome << " - " << eta << "]"; 
	}
	bool eq(Tdato d){  // equal
		return eta == d.eta;
	}
	bool gt(Tdato d){  // greater than
		return eta > d.eta;
	}
	bool lt(Tdato d){  // less than
		return eta < d.eta;
	}
}Tdato;

typedef struct Tnodo{
	Tdato d;
	Tnodo* sx;
	Tnodo* dx;
	Tnodo(){
		d = Tdato();
		sx = dx = NULL;
	}
	Tnodo(Tdato _d){
		d = _d;
		sx = dx = NULL;
	}
	Tnodo(Tdato _d, Tnodo* _sx, Tnodo* _dx){
		d = _d;
		sx = _sx;
		dx = _dx;
	}
	void stampa(){
		d.stampa();
		cout<< endl;
	}
}Tnodo;

typedef Tdato Dato;
typedef Tnodo Nodo;
typedef Tnodo* Tree;

Tree costruisci(Dato d, Tree sx, Tree dx) ;
void inordine(Tree radice) ;

// non richiesto da esercizio
// funzione con funzione come parametro
void stampa(Tree t);
void inordine_gen(Tree radice, void (*f)(Tree));


// Esercizio 2
Tree ins_ord (Tree radice, Dato x);
bool ricerca (Tree radice, Dato x);
bool ricercaBin (Tree radice, Dato x);
// NON richiesti da esercizio:
// mostrano in modo esplicito il numero di invocazioni
bool ricerca_per_valutazione (Tree radice, Dato x, int *n);
bool ricercaBin_per_valutazione (Tree radice, Dato x, int *n);

void delete_all(Tree radice);

// Esercizio 3
void preordine(Tree radice);
void postordine(Tree radice);
int altezza(Tree radice);
int contaFoglie(Tree radice);
int contaNodi(Tree radice);

int max(int n1, int n2);
int altezza(Tree radice);

int lungCammino(Tree radice, int h);

// non richiesto da esercizio
// stampa con struttura grafica
char* convertToStr(int n);
void printnode (char* x, int h);
void draw (Tree l, int h);

#endif
