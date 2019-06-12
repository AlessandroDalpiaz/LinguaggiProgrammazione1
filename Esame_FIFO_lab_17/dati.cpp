#include "dati.h"
#include <iostream>
#include <stdlib.h>

void stampaTpacco(Tpacco t){
	switch(t){
		case ORDINARIO:printf("ORDINARIO\n");break;
		case CELERE:printf("CELERE\n");break;
		case PRIORITY:printf("PRIORITY\n");break;
	}
}
void delPacchi(TcodaFIFO* p[],Tpacco tp){
	FILE *f;
	Tspedizione tmp;
	f = fopen("pacchiOrdinari.txt", "w");
	if(f==NULL)
		return;
	while(p[0]){
		tmp = getFirst(p[0]);
		p[0] = removeFirst(p[0]);
		if(tmp.tipoPacco == tp){
			fprintf(f, "%s PESO=%f\n", tmp.destinatario, tmp.peso);
		}
	}
	fclose(f);
}
Tspedizione getFirst(TcodaFIFO* p){
	Tspedizione tmp;
	tmp=p->dato;	
	return tmp;
}
TcodaFIFO* removeFirst(TcodaFIFO* p){
	if (p==NULL){
		return p;
	}
	TcodaFIFO *q=p->next;
	delete p;
	return q;
}
void addPacco(TcodaFIFO* p[3],Tspedizione s){
	int pos = casuale(0,2);
	if(p[pos]==NULL){
		p[pos]= new TcodaFIFO (s);
	}else{
		p[pos]= new TcodaFIFO(p[pos],s);	
	}
	//p[pos]->stampa();
}
void creaSpedizione(Tspedizione *s){
	s->tipoPacco=(Tpacco)casuale(0, 2);
	fflush(stdin);
	s->peso= casuale(20000,500000)/100.0;
	if(s->tipoPacco!=Tpacco(0))
	{
		s->assicurato=true;
	}
	printf("Destinazione: ");
	scanf("%s",&(s->destinatario));	
}
int casuale(int min,int max){
	return rand()% (max-min+1)+min;
}
void stampaSpedizioni(TcodaFIFO* p[]){
	int i;
	TcodaFIFO* tmp;
	for(i=0 ; i<3 ; i++){
		printf("\ncoda %d\n", i);
		tmp = p[i];
		while(tmp){
			tmp->stampa();
			tmp = tmp->next;
		}
	}
}
