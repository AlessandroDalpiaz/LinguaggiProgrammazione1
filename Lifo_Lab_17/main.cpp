#include "dati.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	int num=0;
	Tnodo *n=NULL;
	Tdato d;	
	while(num!=6){
		printf("Dimmi cosa vuoi fare:\n");
		printf("1 - input Tdato:\n");
		printf("2 - PUSH input da 1:\n");
		printf("3 - STAMPA lista\n");
		printf("4 - READ\n");
		printf("5 - POP\n");
		printf("6 - esci\n");
		scanf("%d",&num);
		switch(num){
			case 1: string s1;string s2; int e;
					printf("Cognome:\n");
					scanf("%s",&s1);
					printf(" Nome: \n");
					scanf("%s",&s2);
					printf(" eta:\n ");
					scanf("%d",&e);
					d= Tdato(s1,s2,e);
					d.stampa();
					break;;
			case 2: printf("PUSH\n");
					n=push(n,d);
					break;;
			case 3: printf("STAMPA\n");
					stampa(n);
					break;;
			case 4: printf("READ\n");
					d= read(n);
					d.stampa();
					break;;
			case 5: printf("POP\n");
					n=pop(n);
					break;;
			default: printf("Ritenta\n");
		}
	}
	/*
	if(daticmp(d,d2))
	{
		printf("TRUE\n");
	}else printf("FALSE\n");*/
	return 0;
}
