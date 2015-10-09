#include <iostream>
#include <sstream>
#include <istream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

enum color {blanco,negro,gris};
enum {inf = -1 };

class grafo{
public:
	class nodo; //FwD
	grafo();
	void rgrafo(int, int, int);
	void insertarPort(int pisoDe,int posDe,int pisoA,int posA);
	void printList(int i);
	void printL(int i);
	void printGraf();
	int distObj();
	void bfs( int init );
	int size();

	class nodo{
	public:
		nodo();
		void rnodo(int piso,int posicion, int L);
		void setNum(int);
		void agregarArista(int piso,int posicion);
		int num();
		nodo *padre();
		color col();
		void printNod();

		nodo& operator=(nodo otro){
			_num=otro._num;
			_padre=otro._padre;
			_col=otro._col;
			_dist= otro._dist;

			return *this;
		}

		int _num;
		nodo* _padre;
		color _col;
		int _dist;
	};

private:
	vector<nodo> nodos;		//Puse esto en public para poder acceder desde bfs
	vector< list<nodo*> > lista;
	int _pisos;
	int _L;
	int _P;
	int _portAct;
};

grafo::nodo::nodo(){
	_padre = NULL;
	_col = blanco;
}

int grafo::size()
{
	return nodos.size();
}

void grafo::nodo::rnodo(int piso,int posicion, int L){
	_num = (piso*L)+posicion;
}

void grafo::nodo::setNum(int num){
	_num = num;
}

int grafo::nodo::num(){return _num;}

grafo::nodo *grafo::nodo::padre(){return _padre;}

color grafo::nodo::col(){return _col;}

void grafo::nodo::printNod(){
	cout << _num;
}

grafo::grafo()
{

}

void grafo::rgrafo(int pisos, int L, int P){
	_pisos=pisos;
	_L=L;
	_P=P;
	_portAct=0;
	int posicion,piso;
	int len = pisos*L;
	nodos.resize(len+P);
	lista.resize(len+P);
	for(int i=0; i<len; i+=L){			
		piso=i/L;

		nodos[i].rnodo(piso,0,L);				//Defino los vertices bordes de los pasillos (casos borde)
		lista[i].push_back(&nodos[i+1]);		
		nodos[i+L-1].rnodo(piso,L-1,L);
		lista[i+L-1].push_back(&nodos[i+L-2]);

		for(int j=i+1;j<i+L-1;j++){				//Defino los vertices de cada metro de cada pasillo (no casos bordes)
			posicion=j%L;
			nodos[j].rnodo(piso,posicion,L);
			lista[j].push_back(&nodos[j-1]);
			lista[j].push_back(&nodos[j+1]);
		}
	}
}


void grafo::printList(int i){
	list<nodo*>::iterator it = (lista[i]).begin();
	list<nodo*>::iterator end = (lista[i]).end();
	while(it!=end){
		cout << (*it)->num() << ", ";
		it++;
	}
}

void grafo::printL(int i){
	printList(i);
	cout << endl;
}

void grafo::printGraf(){
	int size = (_pisos*_L) + _P;
	for(int i=0;i<size;i++){
		cout << nodos[i].num() << ": ";
		printList(i);
		cout << endl;
	}
}

void grafo::insertarPort(int pisoDe,int posDe,int pisoA,int posA){
	nodo portal = nodo();
	int pos = (_pisos*_L) + _portAct;
	portal.setNum(pos);
	_portAct++;
	nodos[pos] = portal;						//Creo los espacios nuevo e inserto el nodo nuevo

	lista[pisoDe*_L + posDe].push_back(&nodos[pos]);
	lista[pisoA*_L + posA].push_back(&nodos[pos]);
	list<nodo*> nueva;
	nueva.push_back(&nodos[pisoDe*_L + posDe]);
	nueva.push_back(&nodos[pisoA*_L + posA]);
	lista[pos] = nueva;
}

int grafo::distObj(){
	return nodos[nodos.size()-_P-1]._dist;
}

void grafo::bfs( int init )
{
	nodo *s = &nodos[init];
	for (nodo& v: nodos)
	{
		v._col = blanco;
		v._dist = inf;
		v._padre = nullptr;
	}

	s->_col = negro;
	s->_dist = 0;
	s->_padre = nullptr;

	std::queue<nodo*> cola;
	cola.push(s);

	while (!cola.empty())
	{
		nodo* v = cola.front();
		cola.pop();

		for (nodo* w: lista[v->_num])
		{
			if (w->_col == blanco)
			{
				w->_col = negro;
				w->_dist = v->_dist + 1;
				cola.push(w);
			}


		}
	}

}
