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


int ej1(std::vector<int> conexiones, std::vector<std::vector<int> > pisos) {
  int n = conexiones.size();
  int max;
  for (int i = 1 ; i < n ; i++) {
    for (int j = 0 ; j < i - 1 ; j++) {
      
    }
  }
}

int evaluarTests(std::string fileTestData, std::string fileTestResult, std::string fileTestWrite) {
  std::string line;
  std::ifstream fileData (fileTestData.c_str());
  std::ifstream fileResult (fileTestResult.c_str());
  std::ofstream fileWrite (fileTestWrite.c_str());
  std::string s;
  std::string res;
  // Abri los archivos de datos y resultados
  // e instancie las variables necesarias para el problema
  // el vector de exploradoras y el vector de amistades 


  while (getline (fileData, line)) {
    int cant_pisos = atoi(line.c_str());
    cant_pisos++;
    std::vector<int> conexiones(cant_pisos);

    for(int i = 0 ; i < cant_pisos ; i++)
      conexiones[i] = -1;

    std::vector<std::vector<int> > pisos(cant_pisos, std::vector<int>(cant_pisos));

    for (int i = 0 ; i < cant_pisos ; i++) {
      for (int j = 0 ; j < cant_pisos ; j++) {
        pisos[i][j] = 0;
      }
    } 

    getline (fileData, line);
    std::istringstream iss(line);
    while (getline (iss, s, ';')) {
      std::istringstream is(s);
      int i;
      is >> i;
      int j;
      is >> j;
      pisos[j][i] = 1;
    }


//    int res = ejUno(conexiones, pisos);
    std::cout << "Matriz adyacencia: " << std::endl;
    for (int i = 0 ; i < cant_pisos ; i++) {
      for (int j = 0 ; j < cant_pisos ; j++) {
        std::cout << " " << pisos[i][j] << " ";
      }
      std::cout << std::endl;
    }

  }

}

int main(int argc, char** argv) {
  std::string fileTestData(argv[1]);
  std::string fileTestResult(argv[2]);
  std::string fileTestWrite(argv[3]);
  // Recibo por parametro tres archivos
  // El primero del cual leo los datos a evaluar
  // El segundo en el cual evaluo si los resultados fueron correctos
  // El tercero donde puedo escribir datos (tiempos)

  evaluarTests(fileTestData, fileTestResult, fileTestWrite);
  
  return 0;
}
