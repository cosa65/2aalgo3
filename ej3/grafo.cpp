#include "grafo.h"

Grafo::Grafo(){}

void Grafo::agregarVertice(Vertice v){
  vertices.insert(v);
  tam += 1;
}

void Grafo::agregarArista(Vertice v1, Vertice v2, int peso){
  Arista a(v1, v2, peso);
  aristas.insert(a);
}

set<Vertice>::iterator Grafo::vertices(){
  return vertices.begin();
}

set<Arista>::iterator Grafo::aristas(){
  return aristas.begin();
}

unsigned int cantVertices(){
  return tam;
}
