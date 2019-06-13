//#ifndef __MYDATA__
//#define __MYADATA__


#include <cstdlib>
#include <iostream>
#include "dati.h"
using namespace std;

#define N_ELEM 5
typedef struct TipoCoda{
	int n;    // numero elementi nella coda
	int dim;  // dimensione max coda
	int head; // elemento in testa
	int tail; // elemento in coda
	int * s;  // elementi -- ARRAY
	TipoCoda(){
		dim=3;
		n=0;
		head=0;
		tail=0;
		s=new int[30]; //creo array
	}
	TipoCoda(int X){
		dim=X;
		n=0;
		head=0;
		tail=0;
		s=new int[30]; //creo array
	}
	~TipoCoda(){	//DISTRUTTORE
		delete s;
	}
	void stampa(){
		if(n==0){
			printf("vuoto\n");
			return;
		}
		int i=head;
		do{
			printf("\t%d",s[i]);
			i++;
		}while(i!=tail);
	}
}TipoCoda;

// Definizione dei tipi
typedef TipoCoda Coda;
typedef TipoCoda *CodaPtr;

// Metodi del tipo di dato astratto Coda FIFO

// Verifica se la coda e' vuota o no
bool CodaIsEmpty(CodaPtr p);

// Verifica se la coda e' piena o no
bool CodaIsFull(CodaPtr p);

// Inserisce l elemento d nella coda aumentandone la dimensione
void Put(CodaPtr p, int x);

// Rimuove un elemento dalla coda, diminuendone la dimensione
int Get(CodaPtr p);

// Stampa il contenuto della coda
void Print(CodaPtr p);


//#endif
