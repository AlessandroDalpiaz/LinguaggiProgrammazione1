#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	printf("inserisci le lettere\n");
	int c;//in base codice ASCII
	while ((c = getchar()) != EOF) {  // EOF ? ctrl Z
		putchar(c);
	}
	return 0;
}
