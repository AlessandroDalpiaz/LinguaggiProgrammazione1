#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "dati.h"

int casuale(int min, int max);
void creaSpedizione(Tspedizione *s);
void addPacco(TcodaFIFO* p[],Tspedizione s);
void stampaSpedizioni(TcodaFIFO *p[]);
void delPacchi(TcodaFIFO* p[], Tpacco tp);
Tspedizione getFirst(TcodaFIFO *p);
TcodaFIFO *removeFirst(TcodaFIFO *p);
int main(int argc, char** argv) {
	TcodaFIFO* p[3] = {NULL, NULL, NULL};
	Tspedizione s;
	for(int i=0; i<5; i++) {
		creaSpedizione(&s);
		addPacco(p,s);
	}
	stampaSpedizioni(p);
	delPacchi(p, ORDINARIO);
	return 0;
}
void stampaSpedizioni(TcodaFIFO *p[]){
	TcodaFIFO * q;
	for(int i=0;i<3;i++){
		q=p[i];
		printf("CODA %d\n",i);
		while(q!=NULL){
			q->stampa();
			q=q->next;
		}
	}
}
void delPacchi(TcodaFIFO* p[], Tpacco tp){
	FILE *f;
	Tspedizione tmp;
	f = fopen("pacchiOrdinari.txt", "w");
	if(f==NULL)
		return;
	while(p[1]){
		tmp = getFirst(p[1]);
		p[1] = removeFirst(p[1]);
		if(tmp.tipoPacco == tp){
			fprintf(f, "%s PESO=%f\n", tmp.destinatario, tmp.peso);
		}
	}
	fclose(f);
}

Tspedizione getFirst(TcodaFIFO *p){
	Tspedizione tmp;
	tmp=p->dato;
	return tmp;
}
TcodaFIFO *removeFirst(TcodaFIFO *p){
	if (p==NULL){
		return p;
	}
	TcodaFIFO * q=p->next;
	delete [] p;
	return q;
}
void addPacco(TcodaFIFO* p[],Tspedizione s){
	int pos =casuale(0,2);
	if(p[pos]==NULL){
		p[pos]=new TcodaFIFO(s);	
	}else{
		p[pos]= new TcodaFIFO(p[pos],s);
	}
}
void creaSpedizione(Tspedizione *s){
	s->tipoPacco=Tpacco(casuale(0,2));
	s->peso=casuale(20000,500000)/100.0;
	if(s->tipoPacco!=ORDINARIO){
		s->assicurato=false;
	}
	printf("destinatario: ");
	scanf("%s",&(s->destinatario));
}
int casuale(int min, int max){
	return rand()% (max-min+1)+min;
}
