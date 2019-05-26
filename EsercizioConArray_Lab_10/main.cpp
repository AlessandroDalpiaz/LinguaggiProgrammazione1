#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define VAL_MIN 'a'
#define VAL_MAX 'z'
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef enum{FALSE, TRUE} Boolean;
/* Genera valori casuali tra i valori min e max */
int casuale(int min, int max);

/* Inizializzazione array */
void init(char vett[], int dim);

/* Stampa array */
void stampa(const char vett[], int dim);

/* Verifica se l'argomento numero e' una vocale. */
Boolean vocale(char c);

/* Stampa le vocali presenti in array */
void stampa_vocali(const char vett[], int dim);

/* Restituisce il minimo tra i due argomenti */
int minimo(int primo, int secondo);

/* Restituisce il minimo carattere */
char cerca_minimo(const char vett[], int dim);

/* Restituisce il carattere con massima frequenza */
char max_occorrenza(const char vett[], int dim, int vmin, int vmax);

int main(int argc, char** argv) {
	char array[200];
	int dim;
	printf("dimensione:");
	scanf("%d",&dim);
	init(array,dim);
	stampa(array,dim);
	
	printf("minimo: %c\n", cerca_minimo(array, dim));
	stampa_vocali(array,dim);
	printf("%c",max_occorrenza(array,dim,'a','z'));
	return 0;
}

int casuale(int min, int max){
	return (rand()%(max-min+1)+ min);
}
void init(char vett[], int dim){
	for(int i=0;i<dim;i++){
		vett[i]=casuale(VAL_MIN,VAL_MAX);
	}
}
void stampa(const char vett[], int dim){
	for(int i=0;i<dim;i++){
		printf("%c, ",vett[i]);
	}
	printf("\n");
}
char cerca_minimo(const char vett[], int dim){
	char c= vett[0];
	for(int i=0;i<dim;i++){
		c= minimo(c,vett[i]);
	}
	return c;
}
int minimo(int primo, int secondo) {
	if(primo<=secondo){
		return primo;
	}
	else {
		return secondo;
	}
    //	return (primo<=secondo ? primo : secondo);
}
Boolean vocale(char c){
	if(c=='a' || c=='e'|| c=='i'|| c=='o'|| c=='u'){
		return TRUE;
	}else {
		return FALSE;
	}
}
void stampa_vocali(const char vett[], int dim){
	for(int i=0;i<dim;i++){
		if(vocale(vett[i])){
			printf("%c ",vett[i]);
		}
	}
	printf("\n");
}
char max_occorrenza(const char vett[], int dim, int vmin, int vmax){
	int occ[vmax-vmin+1];
	int i, imax;
	// azzera occ
	for(i=0 ; i<vmax-vmin+1 ; i++) {   
		occ[i]=0;
	}
	// calcola occorrenze
	for(i=0 ; i<dim ; i++) {   
		occ[vett[i]-vmin]++;
	}
	// cerca massimo
	imax=0;
	for(i=1 ; i<vmax-vmin+1 ; i++) {
		if(occ[i]>occ[imax]){
			imax=i;
		}
	}
	return imax+vmin;
}
