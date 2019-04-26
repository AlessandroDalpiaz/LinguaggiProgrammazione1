#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NCAR 20
typedef char string[NCAR];
bool IsPalindrome(char s[NCAR],int len);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//char stringa[NCAR];
	string parola;
	//char parola[]="Ciao"; opp {'C','i','a','o','\0'};
	
	int len=0;
	//inserisco parola
	printf("digita la parola\n");
	//posso usare anche scanf("%s",&parola);
	gets(parola);
	printf("hai scritto: %s\n",parola);
	
	//ricavo la lunghezza
	while(parola[len]!='\0'){
		len++;
	}
	len =len -1;
	printf("hai scritto: %d\n",len);
	if(IsPalindrome(parola,len)){
		printf("la parola e' palindroma");
	} else{
		printf("la parola non e' palindroma");
	}
	return 0;
}
	bool IsPalindrome(string s,int len){
	int k= len;
	for(int i=0;i<len;i++){
		if(s[i]!=s[k]){
			return false;
		}
		k--;
	}
	return true;
}
