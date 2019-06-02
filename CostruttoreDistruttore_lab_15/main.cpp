#include <cstdlib>
#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Tdata {
	int giorno;
	int mese;
	int anno;
	//DISTRUTTORE ALT + 126 
	~Tdata(){
		cout << "data distrutta"<<endl;
	}
	Tdata(){ //COSTRUTTORE DI DEFAULT
		giorno=mese=anno=0;
	}
	Tdata(int g, int m, int a){ //Costruttore 3 ingressi
		giorno=g;
		mese=m;
		anno=a;
	}
	void stampa(){ //funzione
		printf("%d/%d/%d\n",giorno,mese,anno);
	}
}Tdata;
int main(int argc, char** argv) {
	Tdata data(01,01,2019);
	data.stampa();
	return 0;
}
