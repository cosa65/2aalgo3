class UnionFind {
  
  public:
    
  UnionFind(unsigned int); //tal vez deberia devolver la posicion de memoria
  unsigned int encontrarRep(unsigned int); //devuelve el elemento representante de la clase
  void unir(unsigned int, unsigned int); //une a los dos conjuntos a los cuales pertenecen los dos elementos
  bool mismoRep(unsigned int, unsigned int); //TRUE si tienen el mismo representante, FALSE si no.
  
  private:
  
  void link(Grafo, Grafo);
    
    struct Lista {
    
    Nodo* primero;
    Nodo* ultimo;
    unsigned int longitud;


    };
    struct Nodo {
           
      Lista* set;
      Nodo* siguiente;
    
    };

  vector<Lista*> conjunto;
  vector<Nodo*> siguiente;
 // vector<unsigned int> representantes;
 // vector<Nodo*> conjuntos;



  
   
    
};
