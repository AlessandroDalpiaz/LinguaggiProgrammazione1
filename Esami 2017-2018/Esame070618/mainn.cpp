#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int i, j, temp;
	int seq[N];   
	 i = 0;     
	 while (i < N) {
	 scanf("%d",&seq[i++]); 
 }   
   j = 1;    
    while (j < N){       
	  temp = seq[j];       
	     i = j -1;     
		     while (i >= 0 && seq[i] > temp){ 
			        printf("temp=%d\n",temp);
					    seq[i+1] = seq[i];
						    i = i -1; 
							 }
							  seq[i+1] = temp;
							   j += 1; 
							   
							 } 
			printf("il risultato dell'algoritmo e': ");     
			for( i = 0;i < N; ++i){
				printf("%d",seq[i]);
			}
	
	return 0;
}
