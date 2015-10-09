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

UnionFind::~UnionFind() {
  int n = conjuntos.size();
  for (int i = 0 ; i < n ; ++i) {
    if (conjuntos[i] != NULL)
      delete(conjuntos[i]);
  }
}

Vertice UnionFind::encontrarRep(Vertice x)
{
  return representantes[x] ;  
} 



void UnionFind::unir(Vertice x, Vertice y)
{
  Conjunto* c1 = conjuntos[representantes[x]];
  Conjunto* c2 = conjuntos[representantes[y]];
  if (c1->cardinal >= c2->cardinal){
    representantes[y] = representantes[x];
    conjuntos[y] = NULL;
    //delete(conjuntos[y]);
  } else {
    representantes[x] = representantes[y];
    conjuntos[x] = NULL;
    //delete(conjuntos[x]);
  }
  link(c1, c2);    
} 

bool UnionFind::mismoRep(Vertice x, Vertice y)
{
  Vertice aux1 = encontrarRep(x);
  Vertice aux2 = encontrarRep(y);
  return aux1 == aux2;
}

void UnionFind::link(Conjunto* c1, Conjunto* c2){
  if (c1->cardinal >= c2->cardinal){
//si el cardinal del primero es mas grande, uno el conj 2 al uno    
    c1->ultimo->siguiente = c2->primero;
    Nodo* n = c2->primero;
    unsigned int rep = c1->primero->dato;
    while(n != NULL){
      n->set = c1;
      representantes[n->dato] = rep;
      n = n->siguiente;
    }
    c1->ultimo = c2->ultimo;
    c1->cardinal += c2->cardinal;
    c2->primero = NULL;
    delete(c2);
  } else {
//si no, uno c1 al segundo conjunto
    c2->ultimo->siguiente = c1->primero;
    Nodo* n = c1->primero;
    unsigned int rep = c2->primero->dato;
    while(n != NULL){
      n->set = c2;
      representantes[n->dato] = rep;
      n = n->siguiente;
    }
    c2->ultimo = c1->ultimo;
    c2->cardinal += c1->cardinal;
    c1->primero = NULL;
    delete(c1);
  }
}
