#include "unionFind.h"
using namespace std;

UnionFind::UnionFind(unsigned int n)
{
 // vector<Lista*> conjunto(n);
 // for (int i = 0; i < n; ++i) {
 //   conjunto[i] = i;
 //   Lista* l = new Lista();
    
 // }

} 

unsigned int UnionFind::encontrarRep(unsigned int x)
{
  return representantes[x] ;  
} 



void UnionFind::unir(unsigned int x, unsigned int y)
{
    
} 

bool UnionFind::mismoRep(unsigned int x, unsigned int y)
{
  unsigned int aux1 = encontrarRep(x);
  unsigned int aux2 = encontrarRep(y);
  return x == y;
}

void UnionFind::link(UnionFind f, UnionFind u){
    
  
}

int main() 
{

  return 0;  
}
