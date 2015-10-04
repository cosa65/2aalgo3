#include "ej2.h"

void ejercicio2(string input, string fileOut){
	string line;
	ifstream fileInput(input.c_str());
	ofstream out(fileOut.c_str());
	
	while(getline(fileInput,line)){
		istringstream iss(line);
		int pisos, L;
		iss >> pisos >> L;

		grafo pabellon;
		int pisoDe,posDe,pisoA,posA;

		getline(fileInput,line);
		int P=0;
		if(line.size()>=7){
			P = 1 + (line.size()-7)/9;
		}

		pabellon.rgrafo(pisos,L+1,P);

		istringstream is1(line);
		int pyCom;
		while(P > 0){
			is1 >> pisoDe;
			is1 >> posDe;
			is1 >> pisoA;
			is1 >> posA;
			pabellon.insertarPort(pisoDe, posDe, pisoA, posA);
			P--;
			is1.seekg(is1.tellg()+=2);
		}
		//pabellon.printGraf();

		pabellon.bfs(0); //Corro BFS desde la raiz
		int d = pabellon.distObj();	//Pregunto la distancia al último nodo, el objetivo
		//cout << d << endl;

		out << d << endl;
	}

	//FILE* out; out = fopen(fileOut.c_str(),"w");
	//fprintf(out, "%d\n", d);
}

int main(int , char **argv)
{
	string fileInput(argv[1]);
	string fileOut(argv[2]);
	ejercicio2(fileInput, fileOut);
}