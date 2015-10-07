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


timeval start, end;
double acum = 0;

void init_time() {
  gettimeofday(&start, NULL);
}

double get_time() {
  gettimeofday(&end, NULL);
  return (1000000*(end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec))/1000000.0;
}

//Funciones y datos utilizados para la toma de tiempos

int ejUno(std::vector<int> conexiones, std::vector<std::vector<int> > pisos) {
  init_time();
  int n = conexiones.size();
  int max = 0;
  for (int i = 1 ; i < n ; i++) {
    for (int j = 0 ; j < i ; j++) {
      if (pisos[j][i] == 1) {
        if (max < conexiones[j])
          max = conexiones[j];
      }
    }
    conexiones[i] = max + 1;
    max = 0;
  }
  acum += get_time();
  return conexiones[n-1];
}

int evaluarTests(std::string fileTestData, std::string fileTestResult, std::string fileTestWrite) {
  std::string line;
  std::ifstream fileData (fileTestData.c_str());
  std::ifstream fileResult (fileTestResult.c_str());
  std::ofstream fileWrite (fileTestWrite.c_str());
  std::string s;
  std::string res;
  int i = 1;
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
      pisos[i][j] = 1;
    }


    for (int k = 0 ; k < 100 ; k++) {
      int res = ejUno(conexiones, pisos);
    }

    double prom = acum/100;
    fileWrite << "Test numero: " << i << " cantidad de pisos: " << cant_pisos << std::endl;
    fileWrite << std::fixed << acum << std::endl;
    fileWrite << std::fixed << prom << std::endl;
    acum = 0;


    //std::cout << "Matriz adyacencia: " << std::endl;
    //for (int i = 0 ; i < cant_pisos ; i++) {
    //  for (int j = 0 ; j < cant_pisos ; j++) {
    //    std::cout << " " << pisos[i][j] << " ";
    //  }
    //  std::cout << std::endl;
    //}

    //getline (fileResult, line);

    // Lei una linea del archivo de resultados
    // y pregunto si ya termine de evaluar todos los tests

    //int resTest = atoi(line.c_str());
    //// convierto a int

    //if (res == resTest) {
    //  std::cout << "Paso el test " << i << ". Felicitaciones!" << std::endl;
    //} else {
    //  std::cout << "Fallo el test " << i << ". :(" << std::endl;
    //  std::cout << "Obtuve " << res << " deberia tener " << resTest << std::endl;
    //}

    //i++;

  }
  return 0;
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
