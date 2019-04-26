#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> /*libreria matematica*/
#define N_DIMENSIONI 2
#define N_PUNTI 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	float m[N_PUNTI][2]; //coordiante x, y
	float x, y, dist_min, dist, deltax, deltay;
	int i, p_min;
	for(i=0 ; i<N_PUNTI ; i++){
		m[i][0] = (rand()%100000)/1000.0;
		m[i][1] = 1.0*(rand()%100000)/1000.0;
		printf("coordinate [x y]: ");
		scanf("%f %f", &x, &y);
		p_min=0; // definire minimo a priori
		deltax = m[p_min][0] - x;
		deltay = m[p_min][1] - y;
		dist_min = sqrt(deltax*deltax + deltay*deltay);
		for(i=1 ; i<N_PUNTI ; i++){
			deltax = m[i][0]-x;
			deltay = m[i][1]-y;
			dist = sqrt(deltax*deltax + deltay*deltay);
			if(dist < dist_min){
				p_min = i;
				dist_min = dist;
			}
		}
		printf("\nPunto minima distanza: %f %f",m[p_min][0], m[p_min][1]);
	}
// for(i=0 ; i<NPUNTI ; i++)
// printf("%f %f\n", m[i][0], m[i][1]);
	return 0;
}
