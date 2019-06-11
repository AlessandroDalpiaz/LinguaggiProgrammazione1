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
	bool eq(Tdato d){
		if(index==d.index && value ==d.value){
			return true;
		}else return false;
	}
	bool lt(Tdato d){	//verifico per index
		if(index<d.index){
			return true;
		}else return false;
	}
	bool gt(Tdato d){	//verifico per index
		if(index>d.index){
			return true;
		}else return false;
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
	~Tnodo(){
		printf("distrutto\n");
	}	
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
//
Nodoptr search_remove (Nodoptr p, Dato d);
//
Nodoptr insert_order(Nodoptr s, Tdato d);

int main(int argc, char** argv) {
	Dato d = Dato();
	Dato dn = Dato();
	Nodoptr x = NULL;
	dn.index = 5; dn.value = 22.4;
	
	d.index = 2; d.value = 10.4;
	x= insert_first (x,d);
	
	d.index = 1; d.value = -1.5;
	x = insert_last (x,d);
	
	d.index = 4; d.value = 0.0;
	x = insert_first (x,d);
	printf("\t STAMPA \n");
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

/////////////////////////////////////////////////
	printf("\n\t INSERT FIRST \n");
	d.index = 2; d.value = 10.4;
	x= insert_first (x,d);
	
	printf("\n\t INSERT LAST \n");
	d.index = 3; d.value = -1.5;
	x = insert_last (x,d);
	
	printf("\n\t INSERT FIRST \n");
	d.index = 4; d.value = 0.0;
	x = insert_first (x,d);
	stampa(x);
	/////////////////////////////////////////
	printf("\n\t RIMUOVO A SCELTA \n");
	x = search_remove (x,d);
	stampa(x);
	
	/////////////////////////////////////////
	printf("\n\t insert_order \n");	
	x=insert_order(x, dn);
	stampa(x);
	
	/*-------------test............*/
	printf("\n");
	x->dato.stampa();
	x->next->next->dato.stampa();
	printf("x->next->next  %d\n",x->next->next);
	printf("x->next  %d\n",x->next);
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
	Nodoptr h=s;
	while (h->next!=NULL){ //cerco il puntatore prossimo disponibile, ovvero =NULL
		h->stampa();
		h=h->next;	
	}
	if(h->next==NULL){
		h->stampa();
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
		q->next=NULL;//q->next->next;
	}
	return s;
}
Nodoptr search_remove (Nodoptr p, Dato d){
	if (p != NULL) {
		Nodoptr q = p;
		if ( q->dato.eq (d) ) {
			p = p->next;
			delete q;
			return p;
		}
		else {
			while(q->next != NULL) {
				if ( q->next->dato.eq(d) ) {
				Nodoptr r = q->next;
				q->next = q->next->next;
				delete r;
				return p;
				}
				// if (q->next != NULL)
				q=q->next;
			}
		}
	}
	return NULL;
}
Nodoptr insert_order(Nodoptr s, Tdato d){
	if ((s==NULL) || s->dato.gt(d) ) {
		return insert_first(s, d);
	}
	Nodoptr q=s;
	while((q->next!=NULL)&&q->next->dato.lt(d)){
		q=q->next;
	}
	q->next=new Nodo(d,q->next);
	return s;
}

