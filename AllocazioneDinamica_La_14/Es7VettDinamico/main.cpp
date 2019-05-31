#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define MIN 2
#define MAX 8
typedef struct Tdato{
	int k;
	char c;
}Tdato;
typedef struct Tnodo{
	int n;
	Tdato *p;
}Tnodo;
int random(int min,int max);

int main(int argc, char** argv) {
	Tnodo *v[N];
	//inizializzo
	for(int i=0; i<N;i++){
		v[i]=>n=random(MIN,MAX);
		v[i].p=new Tdato[v[i].n];
	}
	
	//inizializzo array p
	for(int i=0; i<10; i++){
		for(int j=0; j<v[i].n; j++){
	    	v[i].p[j].c = random('a','z');
	    	v[i].p[j].k = random(0,99);      
		}        
	}
	printf("Stampa\n");
	//stampa
  	for(int i=0; i<10; i++){
  		printf("num %d\n",i);
    	for(int j=0; j<v[i].n; j++){
       		printf("[%c,%d]",v[i].p[j].c, v[i].p[j].k);
     	}
     	printf("\n");
	}
  	//disallocazione
  	for(int i=0; i<10; i++){
		delete[] v[i].p;     
  	}
	
	
	
	delete[] v;
	
	return 0;
}
int random(int min,int max){
	return rand()% (max-min+1)+min;
}

