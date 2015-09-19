using namespace std;

class Arista {
  
  public:
    
    Arista();
    Arista(unsigned int, unsigned int, int); 
    int damePeso(); 
    unsigned int vertice1();
    unsigned int vertice2(); 

    bool operator <(Arista a) const;
    bool operator >(Arista a) const;

  private:
    
    unsigned int v1, v2;
    int peso;

};

