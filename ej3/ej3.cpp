#include "unionFind.cpp"
//#include "arista.cpp"
//
#include <queue>
//#include "grafo.cpp"
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <sys/time.h>

timeval inicio, fin;
double acum = 0;

void init_time() {
  gettimeofday(&inicio, NULL);
}

double get_time() {
  gettimeofday(&fin, NULL);
  return (1000000*(fin.tv_sec-inicio.tv_sec) + (fin.tv_usec-inicio.tv_usec))/1000000.0;
}

unsigned int sumaMinima(Grafo g){
  unsigned int res = 0;

  priority_queue<Arista, vector<Arista>, greater<Arista> > maxAristas;
  set<Arista> aristas = g.dameAristas();
  for (set<Arista>::iterator it = aristas.begin() ; it != aristas.end(); ++it) { //guardo las aristas en un maxHeap segun su peso
    maxAristas.push(*it);
  }

  UnionFind uf(g.cantVertices());
  Arista auxArista;
  int size = maxAristas.size();
  for (int i = 0; i < size; ++i) { //recorro todas las aristas
    auxArista = maxAristas.top();
    if (uf.mismoRep(auxArista.vertice1(), auxArista.vertice2())){
    //si los representantes son iguales, entonces es un peso que tengo que añadir a la suma minima
      res += auxArista.damePeso();
    } else {
    //si no son iguales, tengo que agregar la arista y unir a los arboles
      uf.unir(auxArista.vertice1(), auxArista.vertice2()); //uno las dos componentes conexas
    }
    maxAristas.pop(); //desencolo la arista que acabo de analizar
  }
  acum += get_time();
  return res;
}

void evaluarTests(string fIn, string fOut, string fWrite){
  ifstream fileData (fIn.c_str());
  ifstream fileResult (fOut.c_str());
  ofstream fileWrite (fWrite.c_str());

  string line;
  string s;
 
  Vertice v1;
  Vertice v2;
  int peso;
  Arista a;

  int resEsperado;
  unsigned int numTest = 1;

  while (getline (fileData, line)){ //toma una linea del input
    istringstream iss(line); //inicializa una linea auxiliar con la anterior

    Grafo g;

    while (getline (iss, s, ';')){ //pone en s los valores hasta el caracter ";"
      istringstream is(s); //inicializa un auxiliar con los valores que leyo en la anterior
      is >> v1; //guarda primer valor en v1 y mueve puntero
      is >> v2;
      is >> peso;
      g.agregarArista(v1, v2, peso);
      g.agregarVertice(v1);
      g.agregarVertice(v2);
    }

    for (int k = 0 ; k < 100 ; ++k) {
      unsigned int res = sumaMinima(g);
    }


    double promedio = acum / 100;
    fileWrite << "Test número: " << numTest << endl;
    fileWrite << "Tiempo promedio: " << fixed << promedio << endl;
    acum = 0;

    
  //  getline (fileResult, line);
  //  resEsperado = atoi(line.c_str());

  //  if (res == resEsperado){
  //    cout << "Pasó el test " << numTest << ". La suma mínima es: " << res << endl; 
  //  } else {
  //    cout << " Falló el test " << numTest << ". Obtuve " << res << " debería tener " << resEsperado << endl;
  //  }
    numTest++;
  }
}

int main(int argc, char** argv) {
 
  string fileIn(argv[1]);
  string fileOut(argv[2]);
  string fileWrite(argv[3]);
 
  evaluarTests(fileIn, fileOut, fileWrite);
 
  return 0;
}
