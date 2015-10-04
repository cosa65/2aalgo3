#ifndef ARISTA_H_
#define ARISTA_H_

using namespace std;

typedef unsigned int Vertice;

class Arista {
  
  public:
    
    Arista();
    Arista(Vertice, Vertice, int); 
    int damePeso() const; 
    Vertice vertice1() const;
    Vertice vertice2() const; 

    bool operator <(Arista a) const;
    bool operator >(Arista a) const;

  private:
    
    Vertice v1, v2;
    int peso;

};

#endif
