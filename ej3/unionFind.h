#include <vector>
#include <cstddef>

using namespace std;

class UnionFind {
  
  public:
    
  UnionFind(unsigned int); //tal vez deberia devolver la posicion de memoria
  unsigned int encontrarRep(unsigned int); //devuelve el elemento representante de la clase
  void unir(unsigned int, unsigned int); //une a los dos conjuntos a los cuales pertenecen los dos elementos
  bool mismoRep(unsigned int, unsigned int); //TRUE si tienen el mismo representante, FALSE si no.

  private:
  
  struct Conjunto;
  void link(Conjunto*, Conjunto*);
    
    struct Nodo {
         
      unsigned int dato;
      Conjunto* set;
      Nodo* siguiente;
      
      Nodo(unsigned int d) : dato(d), set(NULL), siguiente(NULL) {}; 
    };
    struct Conjunto {
      Nodo* primero;
      Nodo* ultimo;
      unsigned int cardinal;
      Conjunto() : primero(NULL), ultimo(NULL), cardinal(0) {};  
    };

  vector<Conjunto*> conjuntos; //indexado por representantes
  vector<unsigned int> representantes;
 // vector<unsigned int> representantes;
 // vector<Nodo*> conjuntos;

};
