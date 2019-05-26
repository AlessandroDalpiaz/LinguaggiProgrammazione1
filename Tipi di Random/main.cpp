#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char RandomChar();
int RandomInt();
float RandomFloat();
int main(int argc, char** argv) {
	printf("%Random tra interi ");
	printf("%d\n",RandomInt());
	printf("Random tra caratteri ");
	printf("%c\n",RandomChar());
	printf("Random tra float ");
	printf("%f\n",RandomFloat());
	return 0;
}
int RandomInt(){
	return rand()%(100-0+1)+0;
}
char RandomChar(){
	return rand()%('z'-'a' + 1 ) + 'a';
}
float RandomFloat(){
	//rand()%(max*K-min*K +1)+ min*K)/(float)K
	return rand()%((80*100-2*100+1)+2*100)/(float)100;
}
