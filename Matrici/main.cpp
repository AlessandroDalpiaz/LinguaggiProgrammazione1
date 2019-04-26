#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 8 //matrice quadrata
void stampa(int m[MAX][MAX]);
float media(int m[MAX][MAX]);
void StampaSopraMedia(int m[MAX][MAX],float valore);
void CalcolaSomme(int m[MAX][MAX],int SO,int k);
int main(int argc, char** argv) {
	int m[MAX][MAX];
	for(int i=0; i<MAX;i++){
		for(int j=0; j<MAX;j++){
			m[i][j]= rand()% (100-0+1)+0;
		}
	}
	
	stampa(m);
	float med= media(m);
	printf("Media: %f\n",med);
	printf("Elementi sopra la media:\n");
	StampaSopraMedia(m,med);
	//-------------------------------es 4B
	printf("Valore di soglia? ");
	int SO=0;
	scanf("%d",&SO);
	printf("Valore di k? ");
	int k=0;
	scanf("%d",&k);
	CalcolaSomme(m,SO,k);
	return 0;
}
void stampa(int m[MAX][MAX]){
	for(int i=0; i<MAX;i++){
		for(int j=0; j<MAX;j++){
			if(m[i][j]<10){
				printf("  %d ",m[i][j]);
			}else{
				printf(" %d ",m[i][j]);	
			}
		}
		printf("\n");
	}
}
float media(int m[MAX][MAX]){
	float el=MAX*MAX;
	int somma=0;
	for(int i=0; i<MAX;i++){
		for(int j=0; j<MAX;j++){
			somma=somma + m[i][j];
		}
	}
	return somma/el;
}
void StampaSopraMedia(int m[MAX][MAX],float valore){
	for(int i=0; i<MAX;i++){
		for(int j=0; j<MAX;j++){
			if(m[i][j] >= valore){
				if(m[i][j]<10){
				printf(" %d ",m[i][j]);
				}else{
					printf(" %d ",m[i][j]);	
				}
			}else printf(" -- ");
		}
		printf("\n");
	}
}
void CalcolaSomme(int m[MAX][MAX],int SO,int k){
	int somma=0;
	int valk=0;
	for(int i=0; i<MAX;i++){
		valk= m[i][k];
		for(int j=0; j<MAX;j++){
			if(j!=k){
				somma=valk+m[i][j];
				if(somma>SO){
					printf(" %d ",m[i][j]);
				}	
			}
			somma=0;
		}
	}
}
