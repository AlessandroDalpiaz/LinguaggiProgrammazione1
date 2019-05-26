#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int stampa(int a);
int stampa1(int *a);
int stampa2(int *b);

int main(int argc, char** argv) {
	int a=4;
	printf("(main) a %d\n",a);
	stampa(a);
	printf("(main) a %d\n",a);
	stampa1(&a);
	printf("(main) a %d\n",a);
	stampa2(&a);
	printf("(main) a %d\n",a);
	return 0;
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
