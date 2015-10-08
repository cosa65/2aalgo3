#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(int argc, char **argv){
	string fileName(argv[1]);		//Nombre del archivo de test generado
	int tests = atoi(argv[2]);		//Cantidad de casos de tests apsados
	int N = atoi(argv[3]);
	int L = atoi(argv[4]);
	int seed = atoi(argv[5]);

	ofstream output(fileName.c_str());
	srand(seed);

	int P = rand()%((N-1)*(L+1)*(L+1));

	int Ni, Li, Nf, Lf;

	for(int i = 0; i<tests; i++){
		output << N << " " << L << endl;
		Ni=0;
		Nf = (rand()%N);
		while(Nf!=N-1){							// Esto asegura el camino que necesito
			Nf = (rand()%(N-Nf)) + Nf;
			Li = rand()%(L+1);
			Lf = rand()%(L+1);
			output << Ni << " " << Li << " " << Nf << " " << Lf << "; ";
			Ni = Nf;
		}

		for(int j=0; j<P; j++){
			Ni = rand()%N;
			Nf = rand()%N;
			Li = rand()%(L+1);
			Lf = rand()%(L+1);
			output << Ni << " " << Li << " " << Nf << " " << Lf << "; ";
		}

		output << endl;

	}
} 