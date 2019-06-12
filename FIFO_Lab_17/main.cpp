#include "dati.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#define MAX 20
#define K 15
#define N 3
using namespace std;

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
       	//p[pos]->put(d);      //invocazione del metodo put
       	cout << "situazione CODE dopo PUT"<<endl;
       	for(i=0 ; i<N ; i++){
       		cout << "coda " << i <<endl; 
			p[i]->stampa();
		}
       
    	//scelgo una coda in modo casuale per togliere un dato
       	pos=casuale(0,2);
       	//se la lista non è vuota tolgo un elemento
       	if(p[pos]!=NULL){
        	d = get(p[pos]);     //invocazione della funzione get
           	//d = p[pos]->get();   //invocazione del metodo get
           	cout << "situazione CODE dopo GET"<<endl;
           	for(i=0 ; i<N ; i++){
       			cout << "coda " << i <<endl; 
				p[i]->stampa();
			}
       	}
	}
	printf("\nUNO \n");
    p[0]->stampa();
    printf("DUE \n");
    p[1]->stampa();
    printf("TRE \n");
    p[2]->stampa();
    
    //distruggo tutto
    for(i=0 ; i<N ; i++){
    	p[i]->~Coda();
	}
	return 0;
}
