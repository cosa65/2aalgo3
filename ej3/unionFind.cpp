#include "unionFind.h"

UnionFind::UnionFind(unsigned int n)
{
  for (int i = 0; i < n; ++i) {
    representantes.push_back(i);
    Nodo* n = new Nodo(i);
    Conjunto* c = new Conjunto();
    n->set = c;
    c->primero = n;
    c->ultimo = n;
    c->cardinal = 1;
    conjuntos.push_back(c); 
  }
} 

unsigned int UnionFind::encontrarRep(unsigned int x)
{
  return representantes[x] ;  
} 



void UnionFind::unir(unsigned int x, unsigned int y)
{
  Conjunto* c1 = conjuntos[representantes[x]];
  Conjunto* c2 = conjuntos[representantes[y]];
  if (c1->cardinal >= c2->cardinal){
    representantes[y] = representantes[x];
    conjuntos[y] = NULL;
  } else {
    representantes[x] = representantes[y];
    conjuntos[x] = NULL;
  }
  link(c1, c2);    
} 

bool UnionFind::mismoRep(unsigned int x, unsigned int y)
{
  unsigned int aux1 = encontrarRep(x);
  unsigned int aux2 = encontrarRep(y);
  return aux1 == aux2;
}

void UnionFind::link(Conjunto* c1, Conjunto* c2){
  if (c1->cardinal >= c2->cardinal){
//si el cardinal del primero es mas grande, uno el conj 2 al uno    
    c1->ultimo->siguiente = c2->primero;
    Nodo* n = c2->primero;
    while(n != NULL){
      n->set = c1;
      n = n->siguiente;
    }
    c1->ultimo = c2->ultimo;
    c1->cardinal += c2->cardinal;
  //  delete(c2);
  } else {
//si no, uno c1 al segundo conjunto
    c2->ultimo = c1->primero;
    Nodo* n = c1->primero;
    while(n != NULL){
      n->set = c2;
      n = n->siguiente;
    }
    c2->ultimo = c1->ultimo;
    c2->cardinal += c1->cardinal;
  //  delete(c1);
  }
}
