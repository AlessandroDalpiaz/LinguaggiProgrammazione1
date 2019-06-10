#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Tdato{
	int index;
	float value;
	
	Tdato(){
		index=0;
		value=0.0;
	}
	Tdato(int i,float v){
		index=i;
		value=v;
	}
	~Tdato(){}
	
	void stampa(){
		printf("[ %d - %f ]\n",index,value);
	}
	
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
	Tnodo(Tdato d, Tnodo* n){
		dato = d;
		next = n;
	}
	~Tnodo(){}	
	void stampa(){ 
		dato.stampa();
	}
}Tnodo;

typedef Tdato Dato;
typedef Tnodo Nodo;
typedef Tnodo* Nodoptr;

//inserimento in testa alla lista
Nodoptr insert_first (Nodoptr s, Dato d);
//stampa della lista
void stampa (Nodoptr s);
//conteggio numero elementi della lista
int lung (Nodoptr s);
//inserimento in coda alla lista
Nodoptr insert_last (Nodoptr s, Dato d);
int main(int argc, char** argv) {
	Dato d = Dato();
	Nodoptr x = NULL;
	
	d.index = 2; d.value = 10.4;
	x= insert_first (x,d);
	stampa(x);
	
	d.index = 3; d.value = -1.5;
	x = insert_last (x,d);
	stampa(x);
	
	d.index = 4; d.value = 0.0;
	x = insert_first (x,d);
	stampa(x);
	
	return 0;
}

Nodoptr insert_first (Nodoptr s, Dato d) {
	if(s==NULL){
		return new Nodo(d);
	}
	return new Nodo(d,s);		
}
void stampa (Nodoptr s){
	s->stampa();
}
Nodoptr insert_last (Nodoptr s, Dato d){
	if(s==NULL){
		 
		return new Nodo(d,s);
	}
	Nodo *q=s;
	while (q->next!=NULL){ //cerco il puntatore prossimo disponibile, ovvero =NULL
		q=q->next;		   // come se fosse i++; ma va a puntare il prossimo dato
		printf("aa");		
	}
	//sovrascrivo a quello nullo
	q->next= new Nodo(d);
	return s;
}
