#include "unionFind.h"

UnionFind::UnionFind(const unsigned int n)
{
 // vector<Lista*> conjunto(n);
 // for (int i = 0; i < n; ++i) {
 //   conjunto[i] = i;
 //   Lista* l = new Lista();
    
 // }

} 

unsigned int UnionFind::encontrarRep(const unsigned int x)
{
  return representantes[x] ;  
} 



void UnionFind::unir(const unsigned int x, const unsigned int y)
{
    
} 

bool UnionFind::mismoRep(const unsigned int x, const unsigned int y)
{
  unsigned int aux1 = encontrarRep(x);
  unsigned int aux2 = encontrarRep(y);
  return x == y;
}

void UnionFind::link(UnionFind f, UnionFind u){
    
  
}
