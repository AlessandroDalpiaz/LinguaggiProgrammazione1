#ifndef __DATI_H__
#define __DATI_H__


typedef enum Tpacco { ORDINARIO, CELERE, PRIORITY } Tpacco;
void stampaPacco(Tpacco t);
typedef struct Tspedizione{
	char destinatario[20];
	bool assicurato;
	float peso;
	Tpacco tipoPacco;
	Tspedizione () {
	//	destinatario="AAA";
		assicurato=false;
		peso=0.0;
		tipoPacco=ORDINARIO;
	}
	void stampa(){
		printf("%s PESO=%f PACCO=",destinatario,peso);
		stampaPacco(tipoPacco);
	}
} Tspedizione;
typedef struct TcodaFIFO {
	Tspedizione dato; 
	TcodaFIFO* next;
	TcodaFIFO () {
		dato=Tspedizione();
		next =NULL;
	} 
	TcodaFIFO (Tspedizione d) {
		dato=d;
	}
	TcodaFIFO (TcodaFIFO* n, Tspedizione d) {
		dato=d;
		next=n;	
	}
	void stampa(){
		dato.stampa();
	}
} TcodaFIFO;

void stampaPacco(Tpacco t){
	switch(t){
		case ORDINARIO:printf("ORDINARIO\n");break;
		case CELERE:printf("CELERE\n");break;
		case PRIORITY:printf("PRIORITY\n");break;
	}
}

#endif
