#include "unionFind.cpp"
//#include "arista.cpp"
#include <queue>
#include <set>
#include <iostream>

//typedef unsigned int Vertice; //no se que ondis esto

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


//esto deberia recibir un grafo guachina
unsigned int sumaMinima(set<Arista> aristas, set<Vertice> vertices){
  unsigned int res = 0;

  priority_queue<Arista, vector<Arista>, greater<Arista> > maxAristas;
//  priority_queue<Arista> maxAristas;
  for (set<Arista>::iterator it = aristas.begin(); it != aristas.end(); ++it){ //guardo las aristas en un maxHeap segun su peso
    maxAristas.push(*it);
  }

  //aca deberia crear un unioun find
  UnionFind uf(vertices.size());
  Arista auxArista;
  int size = maxAristas.size();
  for (int i = 0; i < size; ++i){ //recorro todas las aristas
    auxArista = maxAristas.top();
    if (uf.mismoRep(auxArista.vertice1(), auxArista.vertice2())){
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

//void evaluarTest(string fIn, string fOut, string fWrite){
//  
//
//}

int main() {
 // string fileIn(argv[1]);
 // string fileOut(argv[2]);
 // string fileWrite(argv[3]);
 // evaluarTests(fileIn, fileOut, fileWrite);
  Arista a1 = Arista(0,1,3);
  Arista a2 = Arista(1,2,3);
  Arista a3 = Arista(2,0,3);
  set<Arista> aristas;
  aristas.insert(a1);
  aristas.insert(a2);
  aristas.insert(a3);

  set<Vertice> vertices;
  vertices.insert(0);
  vertices.insert(1);
  vertices.insert(2);

  unsigned int res = sumaMinima(aristas,vertices);
  cout << "hare " << res << endl;

  Arista b1 = Arista(0,1,8);
  Arista b2 = Arista(0,4,70);
  Arista b3 = Arista(0,3,63);
  Arista b4 = Arista(1,2,53);
  Arista b5 = Arista(1,4,54);
  Arista b6 = Arista(2,3,10);
  Arista b7 = Arista(2,4,12);
  Arista b8 = Arista(3,4,22);

  set<Arista> aristas2;
  aristas2.insert(b1);
  aristas2.insert(b2);
  aristas2.insert(b3);
  aristas2.insert(b4);
  aristas2.insert(b5);
  aristas2.insert(b6);
  aristas2.insert(b7);
  aristas2.insert(b8);

  set<Vertice> vertices2;
  vertices2.insert(0);
  vertices2.insert(1);
  vertices2.insert(2);
  vertices2.insert(3);
  vertices2.insert(4);

  unsigned int res2 = sumaMinima(aristas2, vertices2);
  cout << "hare2 " << res2 << endl;

  return 0;
}
