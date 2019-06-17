#include "dati.h"
void stampaVeicolo(TcodaFIFO* p){
	TcodaFIFO *f=p;
	for(int i=0;i<f->n;i++){
		f->s[i].stampa();
	}
	return;
	
}

void addVeicolo(TcodaFIFO *p,Tveicolo v){
	if(p->n==p->dim){
			printf("coda piena\n");
	}
	else{
		p->s[p->n]= v;
		p->n++;
		p->tail++;
	}
}

int casuale(int min,int max){
	return rand()% (max-min+1)+min;
}
void creaVeicolo(Tveicolo *v){
	v->tipo=Ttipo(casuale(0,2));
	
	int cill;
	printf("cilindrata= ");
	scanf("%d",&(v->cil));
	if(v->cil>900 && v->cil<4000){
		//sv->kw=(v->cil)\17;
		//char marca[20];
		//scanf("%s",&marca);
		scanf("%s",&(v->marca));
		printf("%s",v->marca);
	}else{
		printf("errore\n");		
	}
}

void stampaTipo(Ttipo t){
	switch(t){
		case AUTO:printf("tipo: AUTO\n");break;;
		case MOTO:printf("tipo: MOTO\n");break;;
		case AUTOBUS:printf("tipo: AUTOBUS\n");break;;
	}
}


void delAuto(TcodaFIFO *p,int c){
	FILE *ff;
	ff=fopen("auto.txt","w");
	for(int i=0;i<p->n;i++){
		if(p->s[i].cil<c){
			Tveicolo v= p->s[p->head];
			p->head++;
			p->n--;
			fprintf(ff,"%s CILINDRATA=%d KW=%f\n",v.marca,v.cil,v.kw);
			
		}
	}
	fclose(ff);
}
