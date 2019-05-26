#include "dati.h"
#include <iostream>
#define MAX_EVENTI 10

Tdata inizializzaData(int a,int me,int g,int o,int mi){
	Tdata data;
	data.anno=a;
	data.giorno=g;
	data.mese=me;
	data.minuti=mi;
	data.ora=o;
	return data;
}
void stampaData(Tdata d){
	printf("%d/%d/%d %d:%d\n",d.giorno,d.mese,d.anno,d.ora,d.minuti);
}
int confrontaDate(Tdata d1, Tdata d2){
	if(d1.anno == d2.anno)
		{ if(d1.mese == d2.mese)
			{ if(d1.giorno == d2.giorno)
				{ if(d1.ora == d2.ora)
					{ if(d1.minuti == d2.minuti)
						return 0;
					if(d1.minuti < d2.minuti)
						return -1;
					return 1;
					}//end if(d1.ora == d2.ora)
				if(d1.ora < d2.ora)
					return -1;
				return 1;
			}//end if(d1.giorno == d1.giorno)
			if(d1.giorno < d2.giorno)
				return -1;
			return 1;
		}//end if(d1.mese == d2.mese)
		if(d1.mese < d2.mese)
			return -1;
		return 1;
	}//end if(d1.anno == d2.anno)
	if(d1.anno < d2.anno)
		return -1;
	return 1;
}
Tevento inizializzaEvento(Tdata inizio, Tdata fine,Tattivita attivita){
	Tevento e;
	e.inizio=inizio;
	e.fine=fine;
	e.attivita=attivita;
	return e;
}
void stampaAttivita(Tattivita a){
	switch(a){
		case LEZIONE: printf("LEZIONE\n");break;
		case STUDIO: printf("STUDIO\n");break;
		case PISCINA: printf("PISCINA\n");break;
		case PALLAVOLO: printf("PALLAVOLO\n");break;
		case APPUNTAMENTO: printf("APPUNTAMENTO\n");break;
	}
}
void stampaEvento(Tevento e){
	printf("Inizio: "); stampaData(e.inizio);
	printf("Fine: "); stampaData(e.fine);
	stampaAttivita(e.attivita);
}
