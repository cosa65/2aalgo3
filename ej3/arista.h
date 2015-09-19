using namespace std;

typedef unsigned int Vertice;

class Arista {
  
  public:
    
    Arista();
    Arista(Vertice, Vertice, int); 
    int damePeso(); 
    Vertice vertice1();
    Vertice vertice2(); 

    bool operator <(Arista a) const;
    bool operator >(Arista a) const;

  private:
    
    Vertice v1, v2;
    int peso;

};

