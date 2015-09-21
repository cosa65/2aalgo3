//#include "arista.cpp"
#include <set>

class Grafo {

  public:

    Grafo();
    void agregarVertice(Vertice);
    void agregarArista(Vertice, Vertice, int); //el int es el peso, si no tiene le pongo 1
    set<Vertice>::iterator vertices();
    set<Arista>::iterator aristas();
    unsigned int cantVertices();
    
  private:

    set<Vertice> vertices;
    set<Aristas> aristas;
    unsigned int tam;
};
