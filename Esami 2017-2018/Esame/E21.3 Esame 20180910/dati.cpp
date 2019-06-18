#include <iostream>
#include <cstdlib>
#include "dati.h"

using namespace std;

int casuale(int min, int max){
	return rand()%(max-min+1)+min;
}

void newOrdine(Tordine* o){
	o->tipoRichiesta = (Trichiesta)casuale(0,2);
	do{
		printf("quantita: ");
		scanf("%d", &o->quantita);
		if(o->quantita<1 || o->quantita>20){
			printf("errore. Reinserisci: 1-20\n");
		}
	}while(o->quantita<1 || o->quantita>20);
	// in fase di test per evitare lunghi inserimenti
	// o->quantita = casuale(1, 20);
	o->prezzo = casuale(1000, 9999)/100.0;
	printf("materiale: ");
	scanf("%s", o->materiale);
	// in fase di test per evitare lunghi inserimenti
	// o->materiale[0] = casuale('a', 'z');
	// o->materiale[1] = casuale('a', 'z');
	// o->materiale[2] = casuale('a', 'z');
	// o->materiale[3] = casuale('a', 'z');
	// o->materiale[4] = '\0';
}

void addOrdine(Tnodo* neg[], int dim, Tordine o){
	int pos = casuale(0, dim-1);
	// inserire nuovo nodo in testa
	neg[pos] = new Tnodo(o, neg[pos], NULL);
	// aggiornare il nodo in seconda posizione (ex primo nodo)
	neg[pos]->next->prev = neg[pos];
}

void stampaNegozi(Tnodo* neg[], int dim){
	int i;
	Tnodo* t;
	for(i=0 ; i<dim ; i++){
		printf("\nnegozio %d\n", i);
		t = neg[i];
		if(t==NULL){
			printf("vuoto\n");
		}else{
			while(t){
				t->stampa();
				t = t->next;
			}
		}
	}
}

Tordine cercaOrdine(Tnodo* neg[], int dim){
	int i;
	Tnodo* t;
	Tordine ret;
	ret.quantita = -1;
	// se tutti negozi senza ordini
	bool no_ordini = true;
	for(i=0 ; i<dim && no_ordini ; i++){
		if(neg[i]!=NULL){
			no_ordini = false;
		}
	}
	if(no_ordini)
		// nessun ordine nei negozi
		return ret;
	// i: indice primo negozio con almeno un ordine
	ret = neg[i]->dato; 
	// ipotizzo primo elemento disponibile come dato con maggior costo
	while(i<dim){
		t = neg[i];
		while(t){
			if( t->dato.prezzo/t->dato.quantita > ret.prezzo/ret.quantita ){
				ret = t->dato;
			}
			t = t->next;
		}
		i++;
	}
	FILE* f = fopen("costoso.txt", "w");
	if(f!=NULL){
		fprintf(f, "%s QTA=%d ", ret.materiale, ret.quantita);
		switch(ret.tipoRichiesta){
			case WEB: fprintf(f, "(WEB)"); break;
			case TELEFONO: fprintf(f, "(TELEFONO)"); break;
			case UFFICIO: fprintf(f, "(UFFICIO)"); break;
			default: fprintf(f, "(??)"); break;
		}
		fprintf(f, " prezzo=%f\n", ret.prezzo);
	}
	return ret;
}
