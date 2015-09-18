

class Grafo {
  
  public:
    
  void crearConj(int); //tal vez deberia devolver la posicion de memoria
  int encontrarRep(int); //devuelve el elemento representante de la clase
  void unir(int, int); //une a los dos conjuntos a los cuales pertenecen los dos elementos
  
  private:
  
  void link(Grafo, Grafo);


  
   
    
};
