#ifndef __MYDATA__
#define __MYDATA__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[20];
typedef struct Tdato{
	char *cognome;
	char * nome;
	unsigned int eta;
	Tdato(){
		cognome="";
		nome="";
		eta=-1;
		printf("\inizialize\n");
	}
	Tdato(char *c,char *n, int e){
		cognome=c;
		nome=n;
		eta=e;
	}
	void stampa(){
		printf("Cognome: %s\n",cognome);
		printf("Nome: %s\n",nome);
		printf("eta: %d\n",eta);	
	}
	~Tdato(){}
	
}Tdato;
typedef struct Tnodo{
	Tdato dato;
	Tnodo* next;
	
	Tnodo(){
		dato=Tdato();
		next=NULL;
	}
	Tnodo(Tdato d){
		dato=d;
		next=NULL;
	}
	Tnodo(Tdato d,Tnodo *n){
		dato=d;
		next=n;
	}
	void stampa(){ 
		dato.stampa();
		printf("\t\t%d",&dato);
		printf("  -> %d\n",next);
	}
}Tnodo;
typedef Tnodo* Nodoptr;
Nodoptr push (Nodoptr p, Tdato d);
Nodoptr pop (Nodoptr p);
Tdato read (Nodoptr n);
void stampa(Nodoptr n);
bool daticmp (Tdato d1, Tdato d2);
int length (Nodoptr p);


#endif
