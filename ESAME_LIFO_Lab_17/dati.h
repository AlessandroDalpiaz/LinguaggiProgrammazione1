#ifndef __MYDATA__
#define __MYDATA__

#include <iostream>
#include <stdlib.h>
#include <string.h>
typedef enum Tmezzo{TRENO,AEREO,TAXI}Tmezzo;
void StampaMezzo(Tmezzo t);
typedef struct Tdata{
	unsigned int gg;
	unsigned int mm;
	unsigned int aa;
	Tdata(){
		gg=mm=aa=0;
	}
	Tdata(int g,int m,int a){
		gg=g;
		mm=m;
		aa=a;
	}
	void stampa(){
		printf("%d/%d/%d",gg,mm,aa);
	}
	~Tdata(){
	}
}Tdata;
typedef struct Tbiglietto{
	Tdata dataViaggio;
	char destinazione[20];
	Tmezzo mezzo;
	Tbiglietto(Tdata d,char dest[20],Tmezzo m){
		dataViaggio=d;
		strcpy(destinazione,dest);
		printf("%s\n",destinazione);
		mezzo=m;
	}
	Tbiglietto(){
		mezzo=AEREO;
	}
	void stampa(){
		dataViaggio.stampa();
		printf(" viaggio ");
		StampaMezzo(mezzo);
		printf(" %s\n",destinazione);
	}
}Tbiglietto;
typedef struct Tnodo{
	Tbiglietto data;
	Tnodo *next;
	Tnodo(){ next=NULL; }
	Tnodo(Tbiglietto d, Tnodo *n=NULL){
		data = d;
		next = n;
	}
	void stampa(){
		data.stampa();
	}
	~Tnodo(){}
}Tnodo;
typedef struct Tbiglietteria{
	int numBiglietti;
	Tnodo* sportello[3];
	Tbiglietteria(){ 
		numBiglietti=0; 
		int i;
		for(i=0 ; i<3 ; i++)
			sportello[i]=NULL;	
	}
	void stampa(){
		//Tnodo *q[]=sportello;
	}
	~Tbiglietteria(){}
}Tbiglietteria;
typedef struct Telem{///per la funzione cercaMezzo
	Tmezzo mezzo;
	int n;
}Telem;

int casuale(int min,int max);
void creaBiglietto(Tbiglietto *x);
int cerca(Tbiglietteria b, Tmezzo m);
void inserisciBiglietto(Tbiglietteria * b,Tbiglietto x);
Telem cercaMezzo(Tbiglietteria);


#endif
