#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MIN 0
#define MAX 20

int main(int argc, char** argv) {
	for(int i=0;i<10;i++){
		printf("numero random: ");
		int n= rand()% (MAX-MIN+1)+ MIN;
		printf("%d\n",n);
		printf("lettera random: ");
		char let= rand()% ('z'-'a'+1)+'a';
		printf("%c\n", let);
	}
	
	return 0;
}
