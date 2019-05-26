#ifndef __MYDATA__
#define __MYDATA__

#include <iostream>
#define MAX_EVENTI 10
typedef struct Tdata{
	int anno;
	int mese;
	int giorno;
	int ora;
	int minuti;
}Tdata;
typedef enum {LEZIONE, PISCINA, APPUNTAMENTO, PALLAVOLO, STUDIO} Tattivita;
typedef struct Tevento{
	Tdata inizio;
	Tdata fine;
	Tattivita attivita;
}Tevento;
void stampaEvento(Tevento e);
typedef struct Tagenda{
	Tevento eventi [MAX_EVENTI];
	int n_eventi;
	
	Tagenda(){
		n_eventi=0;
	}
	void addEvento(Tevento e){
		eventi[n_eventi]=e;
		n_eventi++;
	}
	void stampa(){
		for(int i=0;i<n_eventi;i++){
			printf("Evento in posizione %d\n",i);
			stampaEvento(eventi[i]);
		}
	}
}Tagenda;
Tdata inizializzaData(int a,int me,int g,int o,int mi);
void stampaData(Tdata d);
int confrontaDate(Tdata d1, Tdata d2);
Tevento inizializzaEvento(Tdata inizio, Tdata fine,Tattivita attivita);
void stampaAttivita(Tattivita a);


#endif
