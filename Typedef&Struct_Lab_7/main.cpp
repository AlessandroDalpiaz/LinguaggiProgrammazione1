#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> /*libreria matematica*/
#define LUNGH_MAX 50
#define NUM_ESAMI 3
#define NUM_STUDENTI 4
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef char string[LUNGH_MAX];
typedef struct Tstudente{
	string cognome;
	string nome;
	int esami[NUM_ESAMI];
	void stampa(){
		printf("Studente: %s ",cognome);
		printf("%s;\n",nome);
		for(int i=0;i<NUM_ESAMI;i++){
			printf("Voto Esame %d: %d;\n",i,esami[i]);
		}
	}
}Tstudente;
char LetteraRandom(char min,char max);
void ManualInzializ(Tstudente studente[NUM_STUDENTI]);
void AutoInzializ(Tstudente studente[NUM_STUDENTI]);
void AutoInzializZero(Tstudente studente[NUM_STUDENTI]);//es4
void Stampa(Tstudente studente[NUM_STUDENTI]);
void AssegnaVotiRnd(Tstudente studente[NUM_STUDENTI]);
void CalcolaMedia(Tstudente studente[NUM_STUDENTI]);
int main(int argc, char** argv) {
	
	Tstudente studente[NUM_STUDENTI];	
	AutoInzializ(studente);
	
	return 0;
}

char LetteraRandom(char min,char max){
	return rand()% (max-min+1)+min;
}
void ManualInzializ(Tstudente studente[NUM_STUDENTI]){
	printf("\t***Inserimento dati studenti***\n");	
	for (int i = 0; i < NUM_STUDENTI; i++){
		printf("Inserisci il cognome dello studente:\t");
		scanf("%s",studente[i].cognome);
		//gets(studente[i].cognome);
		
		printf("Inserisci il nome dello studente:\t");
		scanf("%s",studente[i].nome);
		//gets(studente[i].nome);
		for (int j = 0; j < NUM_ESAMI; j++){
			printf("Inserire il voto dell'esame %d:", j);
			scanf("%d", &studente[i].esami[j]);
		}
	}
	Stampa(studente);
}
void AutoInzializ(Tstudente studente[NUM_STUDENTI]){
	printf("\t***Inserimento dati studenti***\n");	
	for (int i = 0; i < NUM_STUDENTI; i++){
		for (int k = 0; k < 6; k++){
			studente[i].cognome[k]=LetteraRandom('A','Z');
			studente[i].nome[k]=LetteraRandom('a','z');
		}
		for (int j = 0; j < NUM_ESAMI; j++){
			studente[i].esami[j]=rand()%(30-18+1)+18;
		}
	}
	Stampa(studente);
}
void AutoInzializZero(Tstudente studente[NUM_STUDENTI]){
	printf("\t***Inserimento dati studenti***\n");	
	for (int i = 0; i < NUM_STUDENTI; i++){
		for (int k = 0; k < 2; k++){
			studente[i].cognome[k]=LetteraRandom('A','Z');
			studente[i].nome[k]=LetteraRandom('a','z');
		}
		for (int j = 0; j < NUM_ESAMI; j++){
			studente[i].esami[j]=0;
		}
	}
	Stampa(studente);
}
void Stampa(Tstudente studente[NUM_STUDENTI]){
	for (int j = 0; j < NUM_STUDENTI; j++){
			studente[j].stampa();
		}
}

