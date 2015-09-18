#include <iostream>
#include <sstream>
#include <istream>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

struct arista{
	int piso;
	int pos;
	int tiempo;
};

struct nodo{
	list<arista> aristas;
	bool activo;									//Si no es un nodo o si sí lo es
	void insertarArista(int piso, int pos, int peso);
};

void nodo::insertarArista(int piso, int pos, int peso){
	arista nueva;
	nueva.piso = piso;
	nueva.pos = pos;
	nueva.tiempo = peso;
	aristas.push_back(nueva);
}

typedef vector < vector< nodo > > grafo;	// Identifico a los nodos por dos valores, piso (filas de la matriz) y metros (columnas de la matriz)

int masCercanoIzq(grafo pabellon, int piso, int pos){
	for(int i=pos-1; i>=0; i--){
		if(pabellon[piso][i].activo){
			return i;
		}
	}
	return -1;
}

int masCercanoDer(grafo pabellon, int piso, int pos){
	int L = pabellon[piso].size();
	for(int i=pos+1; i<L; i++){
		if(pabellon[piso][i].activo){
			return i;
		}
	}
	return -1;
}

void insertarPort(grafo pabellon, int pisoDe, int posDe, int pisoA, int posA){
	pabellon[pisoDe][posDe].insertarArista(pisoA,posA,2);
	pabellon[pisoA][posA].insertarArista(pisoDe,posDe,2);
	int cercanoIzq= masCercanoIzq(pabellon, pisoA, posA);							//Busca puntos en el mismo piso a la Izquierda
	int cercanoDer= masCercanoDer(pabellon, pisoDe, posDe);							//Busca puntos en el mismo piso a la Derecha
	if(cercanoIzq!=-1){
		pabellon[pisoDe][posDe].insertarArista(pisoDe,cercanoIzq,pisoDe-cercanoIzq);
		pabellon[pisoDe][cercanoIzq].insertarArista(pisoDe,posDe,pisoDe-cercanoIzq);
	}
	if(cercanoDer!=-1){
		pabellon[pisoDe][posDe].insertarArista(pisoDe,cercanoDer,cercanoDer-pisoDe);
		pabellon[pisoDe][cercanoDer].insertarArista(pisoDe,posDe,cercanoDer-pisoDe);
	}
}

void ejercicio2(string input, string fileOut){
	grafo pabellon;
	string line;
	ifstream fileInput(input.c_str());
	getline(fileInput,line);
	istringstream iss(line);
	int pisos, L;
	iss >> pisos >> L;
	pabellon.resize(pisos);
	for(int i=0; i<L; i++){
		pabellon[i].resize(L);
	}
	int pisoDe,posDe,pisoA,posA;
	while(getline(fileInput, line, ';')){
		istringstream iss(line);
		iss >> pisoDe >> posDe >> pisoA >> posA;
		insertarPort(pabellon, pisoDe, posDe, pisoA, posA);
	}
}

int main(int argc, char **argv){
	string fileInput(argv[1]);
	string fileOut(argv[2]);
	ejercicio2(fileInput, fileOut);
	return 0;
}