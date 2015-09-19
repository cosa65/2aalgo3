#include "unionFind.h"

UnionFind::UnionFind(unsigned int n)
{
  std::vector conjunto(n);
  for (int i = 0; i < n, ++i) {
    conjunto[i] = i;
    Lista* l = new Lista();
    
  }

} 

unsigned int UnionFind::encontrarRep(unsigned int x)
{
  return representantes[x] ;  
} 



void UnionFind::unir(int x, int y)
{
    
} 

bool UnionFind::mismoRep(unsigned int x, unsigned int y)
{
  unsigned int aux1 = encontrarRep(x);
  unsigned int aux2 = encontrarRep(y);
  return x == y;
}

void UnionFind::link(){
    
  
}

int main() 
{

  return 0;  
}
