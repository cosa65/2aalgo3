#include "unionFind.cpp"
#include <queue>
#include <set>
#include <iostream>

typedef unsigned int Vertice; //no se que ondis esto

class Arista {
  
  public:
    
    Arista() {};
    Arista(unsigned int vertice1, unsigned int vertice2, int p) : v1(vertice1), v2(vertice2), peso(p) {};
    int damePeso() const {return peso;}
    unsigned int vertice1() const {return v1;}
    unsigned int vertice2() const {return v2;}

    bool operator>(const Arista a) const {
      bool res;
      if (damePeso() != a.damePeso()){
        res = damePeso() > a.damePeso();
      } else {
        if (v1 != a.vertice1()){
          res = v1 > a.vertice1();
        } else {
          res = v2 > a.vertice2();
        }
      }
      return res;
    }

  private:
    
    unsigned int v1, v2;
    int peso;

};


//class Grafo {
//
//  private:
//    set<Vertice> vertices;
//    set<Arista> aristas; //invariante: todos los vertices de las aristas tienen que estar incluidos e vertices
//
//  public:
//
//
//}


unsigned int sumaMinima(set<Arista> aristas, set<Vertice> vertices){
  unsigned int res;

  priority_queue<Arista, vector<Arista>, greater<Arista>> maxAristas;
  for (set<Arista>::iterator it = aristas.begin(); it != aristas.end(); ++it){ //guardo las aristas en un maxHeap segun su peso
    maxAristas.push(*it);
  }

  //aca deberia crear un unioun find
  UnionFind uf(vertices.size());
  Arista auxArista;
  for (int i = 0; i < maxAristas.size(); ++i){ //recorro todas las aristas
    auxArista = maxAristas.top();
    if (uf.encontrarRep(auxArista.vertice1()) == uf.encontrarRep(auxArista.vertice2())){
    //si los representantes son iguales, entonces es un peso que tengo que añadir a la suma minima
      res += auxArista.damePeso();
    } else {
    //si no son iguales, tengo que agregar la arista y unir a los arboles
      uf.unir(auxArista.vertice1(),auxArista.vertice2()); //uno las dos componentes conexas
    }
    maxAristas.pop(); //desencolo la arista que acabo de analizar
  }

  return res;

}

int main() {

  return 0;
}
