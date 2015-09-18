#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
//#include <set>
//#include <tuple>
#include <sys/time.h>


int evaluarTests(string fileTestData, string fileTestResult, string fileTestWrite) {
  int j = 1;
  string line;
  ifstream fileData (fileTestData.c_str());
  ifstream fileResult (fileTestResult.c_str());
  ofstream fileWrite (fileTestWrite.c_str());
  string s;
  string res;
  // Abri los archivos de datos y resultados
  // e instancie las variables necesarias para el problema
  // el vector de exploradoras y el vector de amistades 


  while (getline (fileData, line)) {
    int cant_pisos = atoi(line.c_str());
    std::vector<std::vector<int>> pisos(cant_pisos, std::vector<int>(cant_pisos));


    for (int i = 0 ; i < cant_pisos ; i++) {
      for (int j = 0 ; j < cant_pisos ; j++) {
        pisos[i][j] = 0;
      }
    } 

    getline (fileData, line);
    istringstream iss(line);
    while (getline (iss, s, ';')) {
      expl.insert(s[0]);


    }

  }

}

int main(int argc, char** argv) {
  string fileTestData(argv[1]);
  string fileTestResult(argv[2]);
  string fileTestWrite(argv[3]);
  // Recibo por parametro tres archivos
  // El primero del cual leo los datos a evaluar
  // El segundo en el cual evaluo si los resultados fueron correctos
  // El tercero donde puedo escribir datos (tiempos)

  evaluarTests(fileTestData, fileTestResult, fileTestWrite);
  return 0;

  
  return 0;
}
