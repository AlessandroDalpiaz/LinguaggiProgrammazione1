#include "dati.h"

int scriviFile(int v[], int dim, FILE* f){
	int i;
	for(i=0 ; i<dim ; i++){
		fprintf(f, "%d\n", v[i]);
	}
	return 1;
}
int leggiFile(int v[], int* dim, FILE* f){
	(*dim)=0;
	while( !feof(f) ){
		fscanf(f, "%d", &v[(*dim)]);
		if(!feof(f))
			(*dim)++;
	}
	return 1;
}
