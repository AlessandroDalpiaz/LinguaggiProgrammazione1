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
int main(int argc, char** argv) {
	Tnodo *n=new Tnodo();
	Tdato d;
	Tdato d2;
	d.cognome="Rossi";
	d.nome="Lorenzo";
	d.eta=10;
	n=push(n,d);
	d2.cognome="Verdi";
	d2.nome="Giuseppe";
	d2.eta=150;
	n=push(n,d2);
	printf("-----stampa i push-------\n");
	stampa(n);
	printf("---------------- %d\n",length(n));
	printf("-----stampa il pop-------\n");
	n=pop(n);
	//d=read(n);
	stampa(n);
	printf("-----stampa il read-------\n");
	d.stampa();
	if(daticmp(d,d2))
	{
		printf("TRUE\n");
	}else printf("FALSE\n");
	
	return 0;
}

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
