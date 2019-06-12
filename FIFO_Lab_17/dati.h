#ifndef __MYDATA__
#define __MYDATA__


#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#define MAX 20
#define K 15
#define N 3

using namespace std;

typedef char stringa[MAX];
typedef struct Tdato{
	stringa nome;
	stringa cognome;
	int eta;
	Tdato () {
		nome[0]='\0';
		cognome[0]='\0';
		eta=0;
	}
	Tdato (stringa n,stringa c, int e){
		strcpy(nome,n);
		strcpy(cognome,c);
		eta=e;
	}
	void stampa(){
		printf("\tnome: %s\n",nome);
		printf("\tcognome: %s\n",cognome);
		printf("\teta: %d\n",eta);
	}
	bool compare(Tdato d){
		if ((strcmp(nome,d.nome)==0) && (strcmp(cognome,d.cognome)==0) && (eta==d.eta)) {
			return true;
		} else {
			return false;
		}
	}
}Tdato;
typedef struct Tnodo {
	Tdato dato;
	Tnodo * next;	
	Tnodo() {
		next = NULL;
	}
	Tnodo(Tdato x,Tnodo *n) {
		dato = x;
		next = n;
	}
	void stampa(){ 
		dato.stampa(); 
		printf("\t%d",&dato);
		printf("\t%d\n",next);
	}
}Tnodo;
typedef struct TipoCoda{
	Tnodo* head;	// puntatore al primo elemento inserito
					// punta all'elemento che si dovra' leggere con get
	Tnodo* tail;  	// puntatore ultimo elemento inserito
					// put deve inserire nuovo elemento prima di questo            
	TipoCoda(){
		head=NULL;
		tail=NULL;
	}
	void stampa(){
		Tnodo *s = head;
		while (s!=NULL){ 
			s->stampa(); 
			s= s->next; 
		}
		cout << endl;  
	}
	~TipoCoda(){
		cout << "\ndistruttore\n";
		Tnodo* tmp=head;
		while(head!=NULL){
			head = head->next;
			delete tmp;
			tmp = head;
		}
		tail = NULL;
	}
}TipoCoda;
typedef struct TipoCoda Coda;
typedef struct TipoCoda *CodaPtr;

//inserisce x in coda
CodaPtr put (CodaPtr p, Tdato d);
//estrae l’elemento in testa alla lista
Tdato get (CodaPtr p);
int casuale(int min,int max);


#endif
