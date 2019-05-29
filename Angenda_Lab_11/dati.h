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
	int scriviFile(char *nomefile){
		FILE* f;
		//f = fopen("Ciao.txt", "w");
		if((f=fopen(nomefile, "w"))==NULL){
			printf("Errore apertura file. Array w");
			return 0;
		}
		else{
			fprintf(f, "%d\n",n_eventi);
			for(int i=0;i<n_eventi;i++){
				fprintf(f,"----------------------\n");
				fprintf(f, "Inzio: %d/%d/%d %d:%d\n",eventi[i].inizio.giorno,eventi[i].inizio.mese,eventi[i].inizio.anno,eventi[i].inizio.ora,eventi[i].inizio.minuti);
				fprintf(f, "Fine: %d/%d/%d %d:%d\n",eventi[i].inizio.giorno,eventi[i].inizio.mese,eventi[i].inizio.anno,eventi[i].inizio.ora,eventi[i].inizio.minuti);
				switch(eventi[i].attivita){
					case LEZIONE: fprintf(f,"LEZIONE\n");break;
					case STUDIO: fprintf(f,"STUDIO\n");break;
					case PISCINA: fprintf(f,"PISCINA\n");break;
					case PALLAVOLO: fprintf(f,"PALLAVOLO\n");break;
					case APPUNTAMENTO: fprintf(f,"APPUNTAMENTO\n");break;
				}
			}
		}
		fclose(f);
		return 1;
		
	}
	int leggiFile( char *nomefile){//Tagenda *pa,
		
	}
	int scriviFileBin(char *nomefile){
		
	}
	int leggiFileBin(Tagenda *pa, char *nomefile){
		
	}
}Tagenda;
Tdata inizializzaData(int a,int me,int g,int o,int mi);
void stampaData(Tdata d);
int confrontaDate(Tdata d1, Tdata d2);
Tevento inizializzaEvento(Tdata inizio, Tdata fine,Tattivita attivita);
void stampaAttivita(Tattivita a);


#endif
