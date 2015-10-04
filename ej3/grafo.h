#ifndef GRAFO_H_
#define GRAFO_H_

#include <set>
#include "arista.cpp"

using namespace std;

typedef unsigned int Vertice;

class Grafo {

  public:

    Grafo();
    void agregarVertice(Vertice);
    void agregarArista(Vertice, Vertice, int); //el int es el peso, si no tiene le pongo 1
    set<Vertice>::iterator dameVertices();
    set<Arista> dameAristas();
    unsigned int cantVertices();
    
  private:

    set<Vertice> vertices;
    set<Arista> aristas;
    unsigned int tam;
};

#endif
