#include "arista.h"

Arista::Arista(){}

Arista::Arista(Vertice vertice1, Vertice vertice2, int p){
  v1 = vertice1;
  v2 = vertice2;
  peso = p;
}

int Arista::damePeso(){
  return peso;
}

Vertice Arista::vertice1(){
  return v1;
}

Vertice Arista::vertice2(){
  return v2;
}


bool Arista::operator <(Arista a) const {
  bool res;
  if (peso != a.damePeso()){
    res = peso < a.damePeso();
  } else {
    if (v1 != a.vertice1()){
      res = v1 < a.vertice1();
    } else {
      res = v2 < a.vertice2();
    }
  }
  return res;
}

bool Arista::operator >(Arista a) const {
  bool res;
  if (peso != a.damePeso()){
    res = peso < a.damePeso();
  } else {
    if (v1 != a.vertice1()){
      res = v1 < a.vertice1();
    } else {
      res = v2 < a.vertice2();
    }
  }
  return res;
}
