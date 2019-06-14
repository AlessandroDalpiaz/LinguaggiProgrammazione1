#ifndef __fifo.h__
#define __fifo.h__

#include <iostream>
#include <stdlib.h>
#include <string.h>

typedef struct Tdato{
	int val;
	Tdato(){
		val = 0;
	}
	Tdato(int x){
		val = x;
	}
	void stampa(){
		printf("%d ",val);
	}
	
}Tdato;

typedef struct TipoCoda{
	int head;
	int tail;
	int dim;
	int n;
	Tdato *s;
	TipoCoda(int x){
		head=0; 
		tail=0;
		dim = x;
		n = 0;
		s = new Tdato[x]; 
	}
	void Put(Tdato x){
		if(isFull()){
			printf("Coda piena\n");
		}else{
			n++;
			s[tail]=x;
			tail++;
			tail=tail%dim;	
		}	
	}
	Tdato get(){
		Tdato d;
		d=s[head];
		head++;
		n--;
		//DA RICORDAREEEEE
		head=head%dim;
		
		return d;
	}
	bool isEmpty(){
		return n==0;
	}
	bool isFull(){
		return n==dim;
	}
	~TipoCoda(){
		delete s;
	}
	void Stampa(){
		if(n==0) return;
		int i=head;
		do{
			s[i].stampa();
			i=(++i)%dim;
		}while(tail!=i);
	}
}TipoCoda;

typedef TipoCoda Coda;
typedef TipoCoda* CodaPtr;

#endif

