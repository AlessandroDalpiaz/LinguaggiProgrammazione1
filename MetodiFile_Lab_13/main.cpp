#include "dati.h"
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	// Opzione 2 - apertura e chiusua file FUORI funzione
	char nome_file[30] = "esempio.txt";
	int vet2[5] = {10,20,30,40,50};
	int vet2_letto[5];
	int dim, i;
	FILE *ff;
	
	if( (ff=fopen(nome_file, "w"))==NULL){
		printf("errore scrittura file\n");
	}else{
		scriviFile(vet2, 5, ff);
		fclose(ff);
	}
	if( (ff=fopen(nome_file, "r"))==NULL){
		printf("errore lettura file\n");
	}else{
		leggiFile(vet2_letto, &dim, ff);
		fclose(ff);
		printf("Lettura\n");
		for(i=0 ;i<dim ; i++){
			printf("%d ", vet2_letto[i]);	
		}
			printf("\n");
	}
	return 0;
}

