#ifndef __DATI_H__
#define __DATI_H__

#include <string.h>
#include <iostream>
#include <stdlib.h>


typedef enum Ttipo{ AUTO, MOTO, AUTOBUS } Ttipo;
void stampaTipo(Ttipo t);
typedef struct Tveicolo{
	char marca[20];
	int cil;
	float kw;
	Ttipo tipo;
	void stampa(){
		printf("marca: %s\n",marca);
		printf("cil : %d\n",cil);
		printf("kw: %f\n",kw);
		stampaTipo(tipo);
	} 
} Tveicolo;
typedef struct TcodaFIFO {
	int n;
	int dim;
	int head;
	int tail;
	Tveicolo *s;
	TcodaFIFO (int x) {
		dim = x;
		n = 0;
		head = 0;
		tail = 0;
		s = new Tveicolo [x];
	}
	~TcodaFIFO(){
		delete s;
	}
	void stampa(){
		/*for(int i=0;i<n;i++){
			s[i]->stampa();
		}*/
		s->stampa();
	}
	// metodo stampa
} TcodaFIFO;

void creaVeicolo(Tveicolo *v);
void addVeicolo(TcodaFIFO *p,Tveicolo v);
int casuale(int min,int max);
void stampaVeicolo(TcodaFIFO* p);
void delAuto(TcodaFIFO *p,int c);

#endif
