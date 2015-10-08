#include "ej2Timed.h"
#include <sys/time.h>

timeval startt,endd;
void init_time()
{
    gettimeofday(&startt,NULL);
}

double get_time()
{
    gettimeofday(&endd,NULL);
    return (1000000*(endd.tv_sec-startt.tv_sec)+(endd.tv_usec-startt.tv_usec))/1000000.0;
}

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
		int prom=0;
		for(int r=0;r<20;r++){

			init_time();
			pabellon.bfs(0); //Corro BFS desde la raiz
			double tiempo = get_time();
			prom+=tiempo;
		}
		
		prom = prom/20;

		int d = pabellon.distObj();	//Pregunto la distancia al último nodo, el objetivo
		//cout << d << endl;

		out << "Cantidad de Pisos " << pisos << " tiempo: ";
		out << fixed << prom << endl;
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