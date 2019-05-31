#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void scelta(int n);
int main(int argc, char** argv) {
	/*
	1: calcolare lunghezza di una stringa
	2: comparare due stringhe
	3: copiare una stringa	
	0: fine*/
	
	printf("Digita tra questi numeri: 1,2,3,0\n");
	int n=-1;
	scanf("%d",&n);
	scelta(n);
	return 0;
}
void scelta(int n){
	switch(n){
		case 0 :return 0; break;
		case 1 : printf("%d",lunghezzaStr());break;
		case 2 : compareStr();break;
		case 3 : copyStr();break;
	}
}
