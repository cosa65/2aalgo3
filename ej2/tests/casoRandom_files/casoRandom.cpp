
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <tuple>
#include <set>

using namespace std;



int main(int argc, char **argv){
	string fileName(argv[1]);		//Nombre del archivo de test generado
	// int tests = atoi(argv[2]);		//Cantidad de casos de tests apsados
	int N = atoi(argv[2]);
	int L = atoi(argv[3]);
	// int seed = atoi(argv[5]);

	ofstream output(fileName.c_str());
	// srand(seed);
	srand(time(NULL));

	int H = N*(L+1);
	int P = rand()%((H-1)*H/2 +1);
	// int P = rand()%((N-1)*(L+1)*(L+1));

	int Ni, Li, Nf, Lf;


	// for(int i = 0; i<tests; i++){
		
		output << N << " " << L << endl;
		Ni=0;
		// Nf = (rand()%N);
		Nf = 0;

		set<tuple<int,int,int,int>> aristas;

		while( Nf!=N-1 ){							// Esto asegura el camino que necesito

			Nf = (rand()%(N));
			// Nf = (rand()%(N-Nf)) + Nf;
			Li = rand()%(L+1);
			Lf = rand()%(L+1);
			std::tuple<int,int,int,int> arista (Ni, Li, Nf, Lf);
			std::tuple<int,int,int,int> arista2 (Nf, Lf, Ni, Li);

			const bool is_in = aristas.find(arista2) != aristas.end();
			if ( !is_in && !(Ni==Nf && Li==Lf) ) aristas.insert(arista);

			Ni = Nf;
			
		}


		for(int j=0; j<P; j++){
			Ni = rand()%N;
			Nf = rand()%N;
			Li = rand()%(L+1);
			Lf = rand()%(L+1);

			std::tuple<int,int,int,int> arista (Ni, Li, Nf, Lf);
			std::tuple<int,int,int,int> arista2 (Nf, Lf, Ni, Li);

			const bool is_in = aristas.find(arista2) != aristas.end();
			if ( !is_in && !(Ni==Nf && Li==Lf) ) aristas.insert(arista);

		}

		for (std::set<tuple<int,int,int,int>>::iterator i = aristas.begin(); i != aristas.end(); ++i)
		{
			output << get<0>(*i) << " " << get<1>(*i) << " " << get<2>(*i) << " " << get<3>(*i) << "; ";
		}

		output << endl;

	// } //for de cantidad de tests
} 