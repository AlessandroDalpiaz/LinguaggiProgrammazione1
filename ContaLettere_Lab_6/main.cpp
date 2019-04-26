#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int ContaSpazi=0;
	int ContaAltro=0;
	int array[10];
	int c;
	int i=0;
	for(int i=0;i<10;i++){
		array[i]=0;
	}
	while ((c = getchar()) != 'q')
	{
		i=0;
		if(c==10 ||c==32){ //spazio e a capo in ASCII
			ContaSpazi++;
		}
		for(int k=48;k<=57;k++){ //da 0 a 9
			if(c==k){
			array[i]=array[i]+1;
			}
			i++;
		}
		if((c<48 || c>57) && c!=10 && c!=32){ //lettere e altro
			ContaAltro++;				
		}
	}
	printf("hai digitato:\n");
	for(int i=0;i<10;i++){
		printf("%d: %d\n",i,array[i]);
	}
	printf("Spazi: %d\n",ContaSpazi);
	printf("Altri: %d\n",ContaAltro);
	return 0;
}
