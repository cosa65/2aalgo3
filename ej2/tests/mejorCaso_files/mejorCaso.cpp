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
	
	output << N << " " << L << endl;

	output << 0 << " " << 0 << " " << N-1 << " " << L << "; ";

	output << endl;

} 