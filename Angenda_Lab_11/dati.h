#ifndef __MYDATA__
#define __MYDATA__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
		if((f=fopen(nomefile, "w"))==NULL){
			printf("Errore apertura file. Agenda w");
			return 0;
		}
		else{
			fprintf(f, "%d\n",n_eventi);
			for(int i=0;i<n_eventi;i++){
				//fprintf(f,"----------------------\n");
				fprintf(f, "%d %d %d %d %d\n",eventi[i].inizio.giorno,eventi[i].inizio.mese,eventi[i].inizio.anno,eventi[i].inizio.ora,eventi[i].inizio.minuti);
				fprintf(f, "%d %d %d %d %d\n",eventi[i].inizio.giorno,eventi[i].inizio.mese,eventi[i].inizio.anno,eventi[i].inizio.ora,eventi[i].inizio.minuti);
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
	void leggi( char *nomefile){
	FILE* f;
		if((f=fopen(nomefile, "r"))==NULL){
			printf("Errore apertura file. Agenda r");
			
		}
		else{
			fscanf(f, "%d",n_eventi);
		}
		fclose(f);
	}
	int leggiFile( char *nomefile){//Tagenda *pa,
		FILE* f;
		if((f=fopen(nomefile, "r"))==NULL){
			printf("Errore apertura file. Agenda r");
			return 0;
		}
		else{
			int i;
		  	char tmp[20];
		  	int nMax=0;
		  	Tevento e;
		  	fscanf(f, "%d", nMax);
		  	for(i=0 ; i<nMax ; i++) {
		    	fscanf(f, "%d %d %d %d %d", e.inizio.giorno,e.inizio.mese,e.inizio.anno,e.inizio.ora,e.inizio.minuti);
		    	fscanf(f, "%d %d %d %d %d",e.fine.giorno,e.fine.mese,e.fine.anno,e.fine.ora,e.fine.minuti);
		    	fscanf(f, "%s", tmp);
		    	if(tmp=="LEZIONE"){
		    		e.attivita=LEZIONE;
				}
				if(tmp=="APPUNTAMENTO"){
		    		e.attivita=APPUNTAMENTO;
				}
				if(tmp=="STUDIO"){
		    		e.attivita=STUDIO;
				}
				if(tmp=="PALLAVOLO"){
		    		e.attivita=PALLAVOLO;
				}
				addEvento(e);
		  	}
		}
		fclose(f);
		return 1;
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
