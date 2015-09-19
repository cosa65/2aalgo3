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

	int P = (length-3)/8;								//Magia

	pabellon.rgrafo(pisos,L,P);

	while(getline(fileInput, line, ';')){
		istringstream iss(line);
		iss >> pisoDe >> posDe >> pisoA >> posA;
		pabellon.insertarPort(pisoDe, posDe, pisoA, posA);
	}
	pabellon.printGraf();
}

int main(int argc, char **argv){
	string fileInput(argv[1]);
	string fileOut(argv[2]);
	ejercicio2(fileInput, fileOut);
	return 0;
}