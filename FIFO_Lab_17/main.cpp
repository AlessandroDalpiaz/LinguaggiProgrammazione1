#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#define MAX 20
#define K 5
#define N 3
using namespace std;

typedef char stringa[MAX];
typedef struct Tdato{
	stringa nome;
	stringa cognome;
	int eta;
	Tdato () {
		nome[0]='\0';
		cognome[0]='\0';
		eta=0;
	}
	Tdato (stringa n,stringa c, int e){
		strcpy(nome,n);
		strcpy(cognome,c);
		eta=e;
	}
	void stampa(){
		printf("\tnome: %s\n",nome);
		printf("\tcognome: %s\n",cognome);
		printf("\teta: %d\n",eta);
	}
	bool compare(Tdato d){
		if ((strcmp(nome,d.nome)==0) && (strcmp(cognome,d.cognome)==0) && (eta==d.eta)) {
			return true;
		} else {
			return false;
		}
	}
}Tdato;
typedef struct Tnodo {
	Tdato dato;
	Tnodo * next;	
	Tnodo() {
		next = NULL;
	}
	Tnodo(Tdato x,Tnodo *n) {
		dato = x;
		next = n;
	}
	void stampa(){ 
		dato.stampa(); 
		printf("\t%d",&dato);
		printf("\t%d\n",next);
	}
}Tnodo;
typedef struct TipoCoda{
	Tnodo* head;	// puntatore al primo elemento inserito
					// punta all'elemento che si dovra' leggere con get
	Tnodo* tail;  	// puntatore ultimo elemento inserito
					// put deve inserire nuovo elemento prima di questo            
	TipoCoda(){
		head=NULL;
		tail=NULL;
	}
	void stampa(){
		Tnodo *s = head;
		while (s!=NULL){ 
			s->stampa(); 
			s= s->next; 
		}
		cout << endl;  
	}
	~TipoCoda(){
		cout << "\ndistruttore\n";
		Tnodo* tmp=head;
		while(head!=NULL){
			head = head->next;
			delete tmp;
			tmp = head;
		}
		tail = NULL;
	}
}TipoCoda;
typedef struct TipoCoda Coda;
typedef struct TipoCoda *CodaPtr;

//inserisce x in coda
CodaPtr put (CodaPtr p, Tdato d);
//estrae l’elemento in testa alla lista
Tdato get (CodaPtr p);
int casuale(int min,int max);
void stampa(CodaPtr p[2]);
int main(int argc, char** argv) {
	//creo array di puntatori
	CodaPtr p[N];
    Tdato d;
    int i, t,  pos;
	//creo N code vuote!
    for (i=0;i<N;i++) { 
        p[i] = new TipoCoda(); 
    }
    
        srand(time(0));
    
	for(t=0 ; t<K ; t++) { 
		fflush(stdin);
       	system("CLS");
       	printf("nome=");    
		// richiesto
		// cin >> d.nome;
		// per velocizzare test
		d.nome[0] = casuale('A', 'Z');
		d.nome[1] = casuale('a', 'z');
		d.nome[2] = casuale('a', 'z');
		d.nome[3] = '\0';
		
       	printf("cognome=");
		d.cognome[0] = casuale('A', 'Z');
		d.cognome[1] = casuale('a', 'z');
		d.cognome[2] = casuale('a', 'z');
		d.cognome[3] = '\0';
		
       	d.eta= casuale(1,50);
		
		//scelgo una coda in modo casuale per inserire il dato
       	pos=casuale(0,2);
       	put(p[pos], d);   //invocazione della funzione put
	}
	printf("\nUNO \n");
    p[0]->stampa();
    printf("DUE \n");
    p[1]->stampa();
    printf("TRE \n");
    p[2]->stampa();
    
    
	return 0;
}
int casuale(int min ,int max){
	return rand()%(max-min+1)+min;
}
//inserisce x in coda
CodaPtr put (CodaPtr p, Tdato d){
	CodaPtr n;
	n=p;
	Tnodo* q=new Tnodo(d,NULL); // NUOVO ELEMENTO
	if(n->tail==NULL){			//lista vuota
		n->head = q;
	}else{
		n->tail->next=q;
	}
	n->tail=q; //assegno come ultimo nodo
	p=n;
	return p;
}

//da fixare
/*void stampa(CodaPtr p[2]){
	CodaPtr q=p;//???
	for(int i=0;i<=2;i++){
		while(q[i]->head==q[i]->tail){
			q[i]->head->dato.stampa();
			q[i]=q[i]->head;
		}
	}
}
*/
//estrae l’elemento in testa alla lista
Tdato get (CodaPtr p){
	Tdato d; //invoco costruttore di default
	if(p->head==NULL){ //lista vuota
		return d;
	}
	d=p->head->dato;
	//caso 1 solo nodo
	if (p->head->next==NULL) {
		delete p->head;
		p->head=NULL; p->tail=NULL;
	} else {
		Tnodo* s= p->head;
		p->head = p->head->next;
		delete s;
	}
	return d;
}
//inteoria legge il'ultimo elemento inserito
Tdato read(CodaPtr p){
	Tdato d;
	if(p->head!=NULL){
		d=p->head->dato;
	}
	return d;
}
