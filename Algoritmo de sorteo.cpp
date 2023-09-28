#include <iostream>
#include <chrono>
#include <random>

using namespace std;

void genera_randoms(int *arr, int cant) {
    std::random_device rd;   // Obtener una semilla aleatoria del dispositivo
    std::mt19937 gen(rd());  // Inicializar el generador con la semilla
    std::uniform_int_distribution<> distribucion(1, cant*2);
    for (int i=0;i<cant;i++) {
        arr[i]= distribucion(gen);
    }
}


void insercion_directa(int *arr,int n) {
    int x;
    int j;
    for (int i=1;i<n;i++) {
        x=arr[i];
        j=i-1;
        while ((j>=0) && (arr[j]>x)) {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=x;
    }
}

int main() {
    int TAM=8;
    int *arreglo;
  
  	std::cout<<"¿Cuántos experimentos ejecuto?";
  	int numExp<<std::cin;
  
  	for (int i=1;i<=numExp;i++) {
      int n=i*100;
      cout<<"Generando exp "<<i<<"\n";
    	genera_randoms(arreglo,n);
    	insercion_directa(arreglo,n);
      std::cout<<"Arreglo ordenado:"<<"\n";
      for (int i=0;i<n;i++) {
          std::cout<<arreglo[i]<<"\n";
      }
    }
    system("pause")
}