#include "ej2.h"

void ejercicio2(string input, string fileOut){
	string line;
	ifstream fileInput(input.c_str());
    fileInput.seekg (0, fileInput.end);
    int length = fileInput.tellg();
    fileInput.seekg (0, fileInput.beg);
	getline(fileInput,line);
	istringstream iss(line);
	int pisos, L;
	iss >> pisos >> L;

	grafo pabellon;

	int pisoDe,posDe,pisoA,posA;

	int P = (length-3)/8;								//Magia		//Dude, wtf

	pabellon.rgrafo(pisos,L+1,P);

	while(getline(fileInput, line, ';')){
		istringstream iss(line);
		iss >> pisoDe >> posDe >> pisoA >> posA;
		pabellon.insertarPort(pisoDe, posDe, pisoA, posA);
	}
	pabellon.printGraf();

	pabellon.bfs(&pabellon.nodos[0]); //Corro BFS desde la raiz
	int d = pabellon.nodos.back()._dist;	//Pregunto la distancia al último nodo (que es el último portal, hay que arreglarlo cuando no sean las 3.30am, para que pregunte por el último piso)
	cout << d << endl;

	FILE* out; out = fopen(fileOut.c_str(),"w");
	fprintf(out, "%d\n", d);
}

int main(int , char **argv)
{
	string fileInput(argv[1]);
	string fileOut(argv[2]);
	ejercicio2(fileInput, fileOut);
}