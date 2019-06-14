#include <cstdlib>
#include <iostream>
#include "dati.h"
using namespace std;

nodoPtr removeLast(nodoPtr s){
  nodoPtr p;
  p=s;
  if (s==NULL) //lista vuota
  { return s; }
  if (s->next==NULL)  //1 solo elemento
  { delete s; return NULL;}
  while (s->next!=NULL)//mi posiziono sull'ultimo elemento
  { s=s->next; }
  //mi posiziono sul penultimo elemento e lo faccio diventare l'ultimo
  s->prev->next=NULL;
  delete s; 
  return p;
}
nodoPtr removeFirst(nodoPtr s){
  nodoPtr n;
  n = s;
  if (s==NULL) //lista vuota
  { return s; } 
  if (s->next==NULL)  //1 solo elemento
  { delete s; return NULL;}   
  if (s!=NULL) {
    s= s->next;
    s->prev=NULL;  
    delete n;        
  } 
  return s;   
}
void stampa(nodoPtr s)
{
  while (s!=NULL) {
    //cout <<"["<<s->dato.index<<","<<s->dato.value << "]";
    s->stampa();
    s= s->next;    
  }
  cout << endl;
}

nodoPtr insertOrder(nodoPtr s, dati CurrD){
 bool cond;
 nodoPtr p=s;  //indirizzo iniziale 
 if ((s==NULL) || (s->dato.gt(CurrD))) 
 { s = insertFirst(s, CurrD);  return s; }
 //altrimenti mi fermo sull'elemento prima di cui inserire il dato
 do
  { cond = true;
  if (s->next!=NULL)
  {cond =s->next->dato.posizione<=CurrD.posizione; }
  s=s->next;
  }
 while ((s!=NULL) && (cond)); 
  if (s==NULL) //ultimo nodo
 { p=insertLast(p,CurrD); return p;} 

 nodoPtr q = new nodo;//creo il nuovo nodo
 q->dato = CurrD;
 q->prev = s->prev; //(s->prev)<-q
 q->next = s; //q->s
 s->prev->next = q; //(s->prev)->q
 s->prev = q;//q<-s
 
 return p;   
}

nodoPtr insertFirst(nodoPtr s, dati CurrD){
 nodoPtr p=s;  //indirizzo iniziale 
 nodoPtr q = new nodo;
 q->dato = CurrD;
 q->prev = NULL;  // (1)perch? ? il primo nodo
 q->next = s;     // (2)q->s  
 //se lista vuota s=NULL e q->next=NULL corretto
 if (s!=NULL)     //lista non vuota
 { s->prev=q; }   // (3)q<-s
 return q;     
}

nodoPtr insertLast(nodoPtr s,dati CurrD){
 nodoPtr p=s;  //indirizzo iniziale
 nodoPtr q = new nodo; //nodo da inserire
 q->dato = CurrD; //q->dato.d = CurrD.d; 
 q->prev = NULL;  //si collega al nodo precedente
 q->next = NULL;  //ultimo nodo della lista  
 if (s!=NULL){
   while (s->next!=NULL)
     { s=s->next; }
   s->next = q;  //penultimo->ultimo
   q->prev = s;  //penultimo<-ultimo
 }else{
   p = q;  
 }
 return p;
}
nodoPtr put(nodoPtr s, dati CurrD){
   return insertLast(s,CurrD);     
}
nodoPtr get(nodoPtr s){
   return removeFirst(s);    
}
dati readFirst(nodoPtr s){
  return s->dato;   
}

int lung(nodoPtr s){
  int l=0;
  if (s==NULL)
  { return l; }
  do{
    l++;
    s=s->next;       
  }while(s!=NULL);  
  return l;       
}

