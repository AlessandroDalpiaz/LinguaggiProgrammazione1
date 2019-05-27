#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int stampa(int a);
int stampa1(int *a);
int stampa2(int *b);

void somma_uno(int x);
void aggiungi_uno(int * x);

int main(int argc, char** argv) {
	int a=4;
	printf("(main) a %d\n",a);
	stampa(a);
	printf("(main) a %d\n",a);
	stampa1(&a);
	printf("(main) a %d\n",a);
	stampa2(&a);
	printf("(main) a %d\n",a);
	printf("__________________________________________________\n");
	
	a = 12;
	printf("var a - Val: %d – Ind: %d (0x%0x)\n", a, &a, &a);
	somma_uno(a);
	printf("var a - Val: %d – Ind: %d (0x%0x)\n", a, &a, &a);
	aggiungi_uno(&a);
	printf("var a - Val: %d – Ind: %d (0x%0x)\n", a, &a, &a);
	
	
	return 0;
}
void somma_uno(int x) {
x += 1;
printf("\nValore var x: %d\n", x);
}
void aggiungi_uno(int * x) {
*x += 1;
printf("\nValore var x: %d\n", *x);
}

int stampa(int a){
	a=a+1;
	printf("(stampa) %d\n",a);
}
int stampa1(int *a){
	*a=*a+1;
	printf("(stampa1) %d\n",*a);
}
int stampa2(int *b){
	*b=*b+1;
	printf("(stampa2) %d\n",*b);
}
