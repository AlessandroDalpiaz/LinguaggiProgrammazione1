#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Tdato{
	// Add dati
	// add costruttori, distruttore, stampa
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
	void stampa()const{ dato.Stampa(); }
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
	Dato d;
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
	cout << "numero elementi in lista:" << x.lung() << endl;
	return 0;
}
