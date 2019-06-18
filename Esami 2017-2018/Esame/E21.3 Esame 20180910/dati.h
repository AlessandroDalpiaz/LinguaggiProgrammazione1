#ifndef __20181009__
#define __20181009__

#define DIM 2
typedef enum Trichiesta { WEB, TELEFONO, UFFICIO } Trichiesta;

typedef struct Tordine{
	char materiale[20];	
	int quantita;
	float prezzo;
	Trichiesta tipoRichiesta;
	
	Tordine () {
		materiale[0] = '\0';
		quantita = 0;
		prezzo = 0;
		tipoRichiesta = WEB;
	}
	void stampa() {
		printf("%s QTA=%d ", materiale, quantita);
		switch(tipoRichiesta){
			case WEB: printf("(WEB)"); break;
			case TELEFONO: printf("(TELEFONO)"); break;
			case UFFICIO: printf("(UFFICIO)"); break;
			default: printf("(??)"); break;
		}
		printf(" prezzo=%f\n", prezzo);
	}
} Tordine;
typedef struct Tnodo {
	Tordine dato;
	Tnodo* next;
	Tnodo* prev;
   
	Tnodo () {
		dato = Tordine();
		next = prev = NULL;
	}
	Tnodo (Tordine o, Tnodo* n, Tnodo* p) {
		dato = o;
		next = n;
		prev = p;
	}
	void stampa() {
		dato.stampa();
	}
} Tnodo;

int casuale(int min, int max);
void newOrdine(Tordine* o);
void addOrdine(Tnodo* neg[], int dim, Tordine o);
void stampaNegozi(Tnodo* neg[], int dim);
Tordine cercaOrdine(Tnodo* neg[], int dim);

#endif

