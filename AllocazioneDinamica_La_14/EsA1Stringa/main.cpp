#include <iostream>
#define MAX 20
using namespace std;

int cstrlen(char *);
int cstrcmp(char *, char *);
void cstrcpy(char *, char *);
void strprint(char* ) ;

int main (int argc, char * const argv[]) {
	char stringa[MAX], t[MAX];
	int type=1, i;
	printf("\n\t Questo programma consente di calcolare la lunghezza di una stringa, comparare due stringhe oppure copiarle");
	while(type) {
		printf("\n\t Premi 1 per calcolare la lunghezza, 2 per confrontate due stringhe e 3 per copiarle (0 per uscire): ");
		scanf("%d",&type);
		switch(type) {
			case 1:
				printf("\n\t Inserisci la stringa per calcolarne la lunghezza: ");
				scanf("%s",stringa);
				strprint(stringa);
				printf("\n\t La lunghezza della stringa %s e' %d \t\n",stringa,cstrlen(stringa));
				break;
			case 2:
				printf("\n\t Inserisci le stringhe per verificare se sono uguali.");
				printf("\n\t Prima stringa: ");
				scanf("%s",stringa);
				printf("\n\t Seconda stringa: ");
				scanf("%s",t);
				i=cstrcmp(stringa,t);
				if(i==0) {
					printf("\n\t Le due stringhe sono identiche.");
				}
				else if(i>0) {
					printf("\n\t La stringa %s e' maggiore della stringa %s.",stringa,t);
				}
				else {
					printf("\n\t La stringa %s e' minore della stringa %s.",stringa,t);
				}
				break;
			case 3:
				printf("\n\t Inserisci la stringa da copiare: ");
				scanf("%s",stringa);
				cstrcpy(t,stringa);
				printf("\n\t La stringa copiata e' %s",t);
				break;	
		}
	}
	return 0;
}

void strprint(char* s) {
	char* t;
	t = s;
	while(*t) { 
	    printf("%c",*t);
		t++;
    }
}
int cstrlen(char* s) {
	char* t=s;
	while(*t) { t++; }
	//ritorno la differenza tra posizioni in memoria: calcolo tra puntatori!!!
	return t-s;
}

int cstrcmp(char* str1, char* str2) {
	char *s; char *t; 
	for(s=str1, t=str2 ; *s==*t ; s++, t++)  {
		if(*s=='\0') { // implicito *s == *t
			return 0;
		}
	}
	// differenza tra contenuti --> \0 ==> codifica 0
	return *s-*t;
}

void cstrcpy(char* dst, char* src) {
	char *s = dst;
	char *t = src;
	while(*s++=*t++);
}
