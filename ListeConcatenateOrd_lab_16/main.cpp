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
		printf("\t%d",&dato);
		printf("  -> %d\n",next);
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
// rimozione elemento in testa alla lista
Nodoptr remove_first (Nodoptr s);
//
Nodoptr remove_last (Nodoptr s);

int main(int argc, char** argv) {
	Dato d = Dato();
	Nodoptr x = NULL;
	
	d.index = 2; d.value = 10.4;
	x= insert_first (x,d);
	//stampa(x);
	
	d.index = 3; d.value = -1.5;
	x = insert_last (x,d);
	//stampa(x);
	
	d.index = 4; d.value = 0.0;
	x = insert_first (x,d);
	stampa(x);

	printf("\n\t RIMUOVO FIRST \n");	
	x= remove_first(x);
	stampa(x);
	
	printf("\n\t RIMUOVO LAST +elementi \n");
	x= remove_last(x);
	stampa(x);
	
	printf("\n\t RIMUOVO LAST 1 elemento \n");
	x= remove_last(x);
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
	if(s==NULL){
		printf("lista vuota\n");
	}
	while (s->next!=NULL){ //cerco il puntatore prossimo disponibile, ovvero =NULL
		s->stampa();
		s=s->next;	
	}
	if(s->next==NULL){
		s->stampa();
	}
	
}
Nodoptr insert_last (Nodoptr s, Dato d){
	if(s==NULL){	 
		return new Nodo(d,s);
	}
	Nodoptr q=s;
	while (q->next!=NULL){ //cerco il puntatore prossimo disponibile, ovvero =NULL
		q=q->next;		   // come se fosse i++; ma va a puntare il prossimo dato	
	}
	//sovrascrivo a quello nullo
	q->next= new Nodo(d);
	return s;
}
Nodoptr remove_first (Nodoptr s){
	if (s == NULL) {
		return s;
	}
	Nodoptr n = s->next;
	//delete [] s;
	delete s;
	return n;
}
Nodoptr remove_last (Nodoptr s){
	if (s == NULL) {
		return s;
	}
	//--VERIFICO 2 CASI:
	//	 - C'è solo un elemento 
	//	 - Ci sono più elementi 
	Nodoptr q=s;
	if(q->next==NULL){
		//delete[] q;
		delete q;	// elimino l'unico elemento esistente
		s=NULL;		// svuoto la lista		
		//return NULL;
	}else{
		while(q->next->next !=NULL){
			q=q->next;
		}
		//delete [] q->next;
		delete q->next;
		q->next=NULL;
	}
	return s;
}
