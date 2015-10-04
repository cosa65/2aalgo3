#include "grafo.h"

Grafo::Grafo(){}

void Grafo::agregarVertice(Vertice v){
  vertices.insert(v);
}

void Grafo::agregarArista(Vertice v1, Vertice v2, int peso){
  Arista a(v1, v2, peso);
  aristas.insert(a);
}

set<Vertice>::iterator Grafo::dameVertices(){
  return vertices.begin();
}

set<Arista> Grafo::dameAristas(){
  return aristas;
}

unsigned int Grafo::cantVertices(){
  return vertices.size();
}

//int main() {
//  return 0;
//}
