#include <iostream>
using namespace std;
#include "tree.h"

Tree costruisci(Dato d, Tree sx, Tree dx){
	// Tree tmp;
	// tmp = new Nodo();
	// tmp->dato = d;
	// tmp->sx = sx;
	// tmp->dx = dx;
	// return tmp;
	return new Nodo(d, sx, dx);
}

void inordine(Tree radice){
	if(radice == NULL)
		return;
	inordine(radice->sx);
	radice->stampa(); // radice->d.stampa();
	inordine(radice->dx);
	/*
	if(radice != NULL){
		inordine(radice->sx);
		radice->stampa(); // radice->d.stampa();
		inordine(radice->dx);
	}
	*/

}

void stampa(Tree t){
	t->stampa();
}
// invocazione: inordine_gen(root, stampa);
// root: variabile di tipo Tree
// stampa: nome della funzione da invocare
void inordine_gen(Tree radice, void (*f)(Tree)){
	if(radice == NULL)
		return;
	inordine(radice->sx);
	f(radice);
	inordine(radice->dx);
	cout << endl;
}

Tree ins_ord (Tree radice, Dato x) {
	if(radice==NULL)
		return new Nodo(x);
	if( x.gt(radice->d) ){
		radice->dx = ins_ord(radice->dx, x);
	}else{
		// minore o uguale a sinistra
		radice->sx = ins_ord(radice->sx, x);
	}
	return radice;
}

bool ricerca (Tree radice, Dato x){
	if( radice == NULL )
		return false;
	if( radice->d.eq(x) )
		return true;
	return ( ricerca(radice->sx, x) || ricerca(radice->dx, x) );
}

bool ricercaBin (Tree radice, Dato x){
	if( radice == NULL )
		return false;
	if( radice->d.eq(x) )
		return true;
	if( x.gt(radice->d) )
		return ricercaBin(radice->dx, x);
	else
		return ricercaBin(radice->sx, x);
}

/*
bool ricerca_per_valutazione (Tree radice, Dato x, int n){
	cout << n << endl;
	if( radice==NULL )
		return false;
	if( radice->d.eq(x) )
		return true;
	return ( ricerca_per_valutazione(radice->sx, x, n+1) || 
	         ricerca_per_valutazione(radice->dx, x, n+1) );
}
*/
bool ricerca_per_valutazione (Tree radice, Dato x, int *n){
	cout << *n << endl;
	if( radice==NULL )
		return false;
	if( radice->d.eq(x) )
		return true;
	return ( ricerca_per_valutazione(radice->sx, x, &++(*n)) || 
	         ricerca_per_valutazione(radice->dx, x, &++(*n)) );
}

/*
bool ricercaBin_per_valutazione (Tree radice, Dato x, int n){
	cout << n << endl;
	if ( radice==NULL )
		return false;
	if( radice->d.eq(x) )
		return true;
	if( x.gt(radice->d) )
		return ricercaBin_per_valutazione(radice->dx, x, n+1);
	else
		return ricercaBin_per_valutazione(radice->sx, x, n+1);
}
*/
bool ricercaBin_per_valutazione (Tree radice, Dato x, int *n){
	cout << *n << endl;
	if ( radice==NULL )
		return false;
	if( radice->d.eq(x) )
		return true;
	if( x.gt(radice->d) )
		return ricercaBin_per_valutazione(radice->dx, x, &++(*n));
	else
		return ricercaBin_per_valutazione(radice->sx, x, &++(*n));
}

void delete_all(Tree radice){
	if( radice == NULL )
		return;
	delete_all(radice->sx);
	delete_all(radice->dx);
	delete radice;
	return;
}

void preordine(Tree radice){
	if(radice == NULL)
		return;
	radice->d.stampa();
	preordine(radice->sx);
	preordine(radice->dx);
}

void postordine(Tree radice){
	if(radice == NULL)
		return;
	postordine(radice->sx);
	postordine(radice->dx);
	radice->d.stampa();
}

int max(int n1, int n2){
	return n1>n2 ? n1 : n2;
}

int altezza(Tree radice){
	if(radice == NULL)
		return -1;
	int a_sx = altezza(radice->sx);
	int a_dx = altezza(radice->sx);
	if( a_sx > a_dx )
		return a_sx+1;
	else
		return a_dx+1;
}

int altezza_v2(Tree radice){
	if(radice == NULL)
		return -1;
	return 1 + max(altezza_v2(radice->sx), altezza_v2(radice->dx));
}

int contaFoglie(Tree radice){
	if( radice==NULL )
		return 0;
	if( radice->sx==NULL && radice->dx==NULL )
		// foglia
		return 1;
	return contaFoglie(radice->sx) + contaFoglie(radice->dx);
}

int contaNodi(Tree radice){
	if( radice==NULL )
		return 0;
	return 1 + contaNodi(radice->sx) + contaNodi(radice->dx);
}

int lungCammino(Tree radice, int h){
	if( radice==NULL )
		return 0;
	return h + lungCammino(radice->sx, h+1) + lungCammino(radice->dx, h+1);
}

void printnode (char* x, int h) {
   for( int i = 0; i < h; i++) cout << "  ";
   cout << x << endl;
}

char* convertToStr(int n){
	char* tmp = new char[MAXL];
	int i=0;
	do{
		tmp[i] = '0' + n%10;
		i++;
		n = n/10;
	}while(n!=0);
	tmp[i] = '\0';
	// reverse
	int len = i;
	char c;
	for(i=0 ; i<len/2 ; i++){
		c = tmp[i];
		tmp[i] = tmp[len-1-i];
		tmp[len-1-i] = c;
	}
	return tmp;
}

void draw (Tree l, int h) {
   if (l == NULL) { printnode("*", h); return;}
   draw(l->dx, h+1);
   printnode(convertToStr(l->d.eta), h);
   draw(l->sx, h+1);
}
