#include "dati.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void StampaMezzo(Tmezzo t){
	switch(t){
		case TRENO: printf("TRENO");break;
		case AEREO: printf("AEREO");break;
		case TAXI: printf("TAXI");break;
	}
}
Telem cercaMezzo(Tbiglietteria b){
	Telem r;
	// ipotesi: TRENO è il massimo
	r.mezzo = TRENO;
	r.n = cerca(b, r.mezzo);
	// controllo se AEREO è più grande
	int n = cerca(b, AEREO);
	if( n>r.n ){
		r.mezzo = AEREO;
		r.n = n;
	}
	// controllo se TAXI è più grande
	n = cerca(b, TAXI);
	if( n>r.n ){
		r.mezzo = TAXI;
		r.n = n;
	}
	return r;
}
void inserisciBiglietto(Tbiglietteria * b,Tbiglietto x){
	int pos=casuale(0,2);
	fflush(stdin);
	b->sportello[pos]=new Tnodo(x, b->sportello[pos]);
	b->numBiglietti++;
}
int casuale(int min,int max){
	return rand()% (max-min+1)+min;
}
void creaBiglietto(Tbiglietto *x){
	srand(time(0));
	fflush(stdin);
	x->dataViaggio=Tdata(casuale(1,31), casuale(1,12), casuale(2010,2012));
	printf("Destinazione: ");
	scanf("%s",x->destinazione);
	x->mezzo=(Tmezzo)casuale(0,2);
	srand(time(NULL));
	fflush(stdin);
}
int cerca(Tbiglietteria b, Tmezzo m){
	int n;
	for(int i=0;i<3;i++){
		Tnodo *p= b.sportello[i];
		while(p){
			if(p->data.mezzo==m){
				n++;
			}
			p=p->next;
		}
	}
	return n;
}
