
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <tuple>
#include <set>

using namespace std;

int main(int argc, char **argv){
	string fileName(argv[1]);		//Nombre del archivo de test generado
	int N = atoi(argv[2]);
	int L = atoi(argv[3]);

	ofstream output(fileName.c_str());

	int Ni, Li, Nf, Lf;

		
	output << N << " " << L << endl;

	set<tuple<int,int,int,int>> aristas;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < L+1; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				for (int l = 0; l < L+1; ++l)
				{
					std::tuple<int,int,int,int> arista (i, j, k, l);
					std::tuple<int,int,int,int> arista2 (k, l, i, j);
					const bool is_in = aristas.find(arista2) != aristas.end();
					if ( !is_in && !(i==k && j==l) ) aristas.insert(arista);
					
				}
			}
		}
	}

	for (std::set<tuple<int,int,int,int>>::iterator i = aristas.begin(); i != aristas.end(); ++i)
	{
		output << get<0>(*i) << " " << get<1>(*i) << " " << get<2>(*i) << " " << get<3>(*i) << "; ";
	}

	output << endl;

} 