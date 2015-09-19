#include <vector>



using namespace std;


class UnionFind {

  
  public:
    
  UnionFind(const unsigned int); //tal vez deberia devolver la posicion de memoria
  unsigned int encontrarRep(const unsigned int); //devuelve el elemento representante de la clase
  void unir(const unsigned int, const unsigned int); //une a los dos conjuntos a los cuales pertenecen los dos elementos
  bool mismoRep(const unsigned int, const unsigned int); //TRUE si tienen el mismo representante, FALSE si no.

  private:
  
  void link(UnionFind, UnionFind);
    
  struct Lista;
    struct Nodo {
           
      Lista* set;
      Nodo* siguiente;
    
    };
    struct Lista {

    Lista() : primero(nullptr), ultimo(nullptr), longitud(0) {};  
    Nodo* primero;
    Nodo* ultimo;
    unsigned int longitud;


    };

  vector<Lista*> conjunto;
  vector<unsigned int> representantes;
 // vector<unsigned int> representantes;
 // vector<Nodo*> conjuntos;

};
