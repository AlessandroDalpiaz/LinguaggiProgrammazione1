#ifndef __dati.h__
#define __dati.h__


#include <iostream>
#include <cstdlib>
#include "dati.h"

using namespace std;
typedef struct Tdato{
	int x,y,z;
	Tdato(){
		x = 0;
		y=0;
		z=0;
	}
	Tdato(int _x,int _y,int _z){
		x= _x;
		y=_y;
		z=_z;
	}
	void stampa(){
		printf(" [%d,%d,%d] ",x,y,z);
	}
}Tdato;
typedef struct TipoStack {
	int n; // numero elementi presenti
	int dim; // dimensione massima array
	Tdato * s; // array
	TipoStack (int x) { // costruttore
		n = 0;
		dim = x;
		s = new Tdato [x];
	}
	TipoStack(){
		n=0;
		dim=3;
		s = new Tdato [3];
	}
	push(Tdato x){
		if(n==dim){
			printf("pienooooo\n");
		}else{
			s[n]=x;
			n++;	
		}
	}
	Tdato pop(){
		Tdato d;
		d=s[n];
		n--;
		return d;
	}
	isEmpty(){
		return n==0;
	}
	isFull(){
		return n==dim;
	}
	~TipoStack(){
		delete[] s;
	}
	// metodo stampa: se dato presente richiamare metodo
	//stampa di Tdato altrimenti stampare [,,]
	void stampa(){
		for(int i=0;i<n;i++){	
			s[i].stampa();
		}
		int m=n;
		while(m<dim){
			printf(" [ , , ] ");
			m++;
		}
		printf("\n");
	}
} TipoStack;
typedef TipoStack Stack;
typedef TipoStack *StackPtr;


#endif
