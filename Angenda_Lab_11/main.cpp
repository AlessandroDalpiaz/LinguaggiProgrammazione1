#include <iostream>
#define MAX_EVENTI 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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


int main(int argc, char** argv) {
	Tdata d1, d2;
	Tevento e;
	Tagenda a;
	
	d1 = inizializzaData(2009,6,10,10,30);
	d2 = inizializzaData(2009,6,10,11,30);
	e = inizializzaEvento(d1,d2,PISCINA);
	a.addEvento(e);
	d1 = inizializzaData(2009,6,11,14,30);
	d2 = inizializzaData(2009,6,11,16,0);
	e = inizializzaEvento(d1,d2,STUDIO);
	a.addEvento(e);
	d1 = inizializzaData(2009,7,11,16,0);
	d2 = inizializzaData(2009,6,11,16,30);
	e = inizializzaEvento(d1,d2,APPUNTAMENTO);
	a.addEvento(e);
	a.stampa();
	return 0;
}
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
