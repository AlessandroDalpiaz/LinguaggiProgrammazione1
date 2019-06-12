#ifndef __MYDATA__
#define __MYDATA__


#include "dati.h"
#include <iostream>
#include <stdlib.h>

typedef enum Tpacco { ORDINARIO, CELERE, PRIORITY } Tpacco;
void stampaTpacco(Tpacco t);
typedef struct Tspedizione{
	char destinatario[20];
	bool assicurato;
	float peso;
	Tpacco tipoPacco;
	Tspedizione () { 
		destinatario[0] ='\0';
		assicurato=false;
		float peso =0.0;
		tipoPacco=Tpacco(0);
	}
	void stampa(){
		//destinatario PESO=peso PACCO=tipoPacco
		printf("%s PESO=%f PACCO=",destinatario,peso);
		stampaTpacco(tipoPacco);
	}
} Tspedizione;
typedef struct TcodaFIFO {
	Tspedizione dato;
	TcodaFIFO* next;
	TcodaFIFO () { 
		dato= Tspedizione();
		next=NULL;
	}
	TcodaFIFO (Tspedizione d) { 
		dato=d;
	}
	TcodaFIFO (TcodaFIFO* n, Tspedizione d) { 
		dato=d;
		next=n;
	}
	void stampa(){
	 dato.stampa();
	}
} TcodaFIFO ;

int casuale(int min,int max);
void creaSpedizione(Tspedizione *s);
void addPacco(TcodaFIFO* p[],Tspedizione s);
void stampaSpedizioni(TcodaFIFO* p[]);
void delPacchi(TcodaFIFO* p[],Tpacco tp);
Tspedizione getFirst(TcodaFIFO* p);
TcodaFIFO* removeFirst(TcodaFIFO *p);

#endif
