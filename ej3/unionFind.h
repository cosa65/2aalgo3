#ifndef UNIONFIND_H_
#define UNIONFIND_H_

#include <vector>
#include "grafo.cpp"
#include <cstddef>
#include <iostream>

using namespace std;

class UnionFind {
  
  public:
    
  UnionFind(unsigned int); //tal vez deberia devolver la posicion de memoria
  ~UnionFind();
  Vertice encontrarRep(Vertice); //devuelve el elemento representante de la clase
  void unir(Vertice, Vertice); //une a los dos conjuntos a los cuales pertenecen los dos elementos
  bool mismoRep(Vertice, Vertice); //TRUE si tienen el mismo representante, FALSE si no.

  private:
  
  struct Conjunto;
  void link(Conjunto*, Conjunto*);
    
    struct Nodo {
         
      unsigned int dato;
      Conjunto* set;
      Nodo* siguiente;
      
      Nodo(unsigned int d) : dato(d), set(NULL), siguiente(NULL) {}; 
      //~Nodo() {
      //  set = NULL;
      //  siguiente = NULL;
      //}
    };
    struct Conjunto {
      Nodo* primero;
      Nodo* ultimo;
      unsigned int cardinal;

      Conjunto() : primero(NULL), ultimo(NULL), cardinal(0) {};  
      ~Conjunto() {
        if (primero != NULL) {
          Nodo* n = primero; 
          Nodo* aux = primero;
          while (n != NULL) {
            aux = n->siguiente;
            delete(n);
            n = aux;
          }
        }
  //      delete(this);
      }

    };

  vector<Conjunto*> conjuntos; //indexado por representantes
  vector<Vertice> representantes;
 // vector<unsigned int> representantes;
 // vector<Nodo*> conjuntos;

};

#endif
