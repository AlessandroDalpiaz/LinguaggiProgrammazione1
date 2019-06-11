#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MAX 20

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
		cout << "nome:"<<nome<<" cognome:"<<cognome<<" eta:"<<eta <<endl;
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
}Tnodo;
typedef struct TipoCoda{
	Tnodo *head;
	Tnodo *tail;
	TipoCoda(){
		head=NULL;
		tail=NULL;
	}
}TipoCoda;
typedef struct TipoCoda Coda;
typedef struct TipoCoda *CodaPtr;

//inserisce x in coda
CodaPtr put (CodaPtr p, Tdato d);
//estrae l’elemento in testa alla lista
Tdato get (CodaPtr p);

int main(int argc, char** argv) {
	
	return 0;
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
