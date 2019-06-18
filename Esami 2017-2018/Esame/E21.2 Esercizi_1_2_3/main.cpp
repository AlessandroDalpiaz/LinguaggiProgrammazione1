#include <iostream>
#include "tree.h"
using namespace std;

int main(int argc, char** argv) {
	/*
	  main sercizio 2
	*/
	// 5 7 3 2 1 4 9 
	cout << "*************************************" << endl;
	cout << "  esercizio 2" << endl << endl ;
	Tree root2 = NULL;
	
	root2 = ins_ord(root2, Tdato(5) );
	root2 = ins_ord(root2, Tdato(7) );
	root2 = ins_ord(root2, Tdato(3) );
	root2 = ins_ord(root2, Tdato(2) );
	root2 = ins_ord(root2, Tdato(1) );
	root2 = ins_ord(root2, Tdato(4) );
	root2 = ins_ord(root2, Tdato(9) );
	cout << endl << "in order" << endl;
	inordine(root2);	
	
	cout << endl << "draw" << endl;
	draw(root2, 0);
	
	Tdato d(9);
	cout << endl << "ricerca 9" << endl;
	cout << ricerca(root2, d) << endl;
	cout << endl << "ricercaBin 9" << endl;
	cout << ricercaBin(root2, d) << endl;
	
	int n = 0;
	cout << endl << "ricerca_per_valutazione 9" << endl;
	ricerca_per_valutazione(root2, d, &n);
	n=0;
	cout << endl << "ricercaBin_per_valutazione 9" << endl;
	ricercaBin_per_valutazione(root2, d, &n);
	
	d = Tdato(1);
	n=0;
	cout << endl << "ricerca_per_valutazione 1" << endl;
	ricerca_per_valutazione(root2, d, &n);
	n=0;
	cout << endl << "ricercaBin_per_valutazione 1" << endl;
	ricercaBin_per_valutazione(root2, d, &n);
	
	d = Tdato(100);
	n=0;
	cout << endl << "ricerca_per_valutazione 100" << endl;
	ricerca_per_valutazione(root2, d, &n);
	n=0;
	cout << endl << "ricercaBin_per_valutazione 100" << endl;
	ricercaBin_per_valutazione(root2, d, &n);
	
	d = Tdato(0);
	n=0;
	cout << endl << "ricerca_per_valutazione 0" << endl;
	ricerca_per_valutazione(root2, d, &n);
	n=0;
	cout << endl << "ricercaBin_per_valutazione 0" << endl;
	ricercaBin_per_valutazione(root2, d, &n);
	
	delete_all(root2);
	
	getchar();

	/* 
	  main esercizio 1
	*/
	cout << "*************************************" << endl;
	cout << "  esercizio 1" << endl << endl ;
	Tree root1  = NULL;

	root1 = new Nodo( Tdato(5) );	
	
	root1->sx = new Nodo( Tdato(7) );
	root1->dx = new Nodo( Tdato(5) );
	
	root1->sx->sx = new Nodo( Tdato(2) );
	root1->sx->dx = new Nodo( Tdato(1) );
	
	root1->dx->sx = new Nodo( Tdato(4) );
	root1->dx->dx = new Nodo( Tdato(9) );
	
	inordine(root1);
	
	getchar();
	
	// non richiestao da esercizio 
	// void inordine_gen(tree radice, void (*f)(tree));
	inordine_gen(root1, stampa);
	
	getchar();
	// draw
	cout << endl << "draw" << endl;
	draw(root1, 0);
	
	delete root1->dx->dx;
	delete root1->dx->sx;
	delete root1->sx->dx;
	delete root1->sx->sx;
	delete root1->dx;
	delete root1->sx;
	delete root1;
	
	getchar();

	
	/*
	  main sercizio 3
	*/
	// 5 7 3 2 1 4 9 
	cout << "*************************************" << endl;
	cout << "  esercizio 3" << endl << endl ;
	
	Tree root3 = NULL;
	
	root3 = ins_ord(root3, Tdato(5) );
	root3 = ins_ord(root3, Tdato(7) );
	root3 = ins_ord(root3, Tdato(3) );
	root3 = ins_ord(root3, Tdato(2) );
	root3 = ins_ord(root3, Tdato(1) );
	root3 = ins_ord(root3, Tdato(4) );
	root3 = ins_ord(root3, Tdato(9) );
	
	cout << endl << "draw" << endl;
	draw(root3, 0);
	
	cout << endl << "in order" << endl;
	inordine(root3);	
	
	cout << endl << "pre order" << endl;
	preordine(root3);	
	
	cout << endl << "post order" << endl;
	postordine(root3);	
	
	cout << endl << "altezza:" << altezza(root3) << endl;
	cout << endl << "foglie:" << contaFoglie(root3) << endl;
	cout << endl << "nodi:" << contaNodi(root3) << endl;
	cout << endl << "lung cammino:" << lungCammino(root3, 0) << endl;
	
	delete_all(root3);
	
	getchar();
	return 0;
}
