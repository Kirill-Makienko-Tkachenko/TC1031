#include <chrono>
#include <iostream>
#include <random>

using namespace std;
using namespace std::chrono;


// x= valor a buscar, i= inicio del vector, n=cantida de elementos
int bin_rec(int *arr, int x, int i, int n) {
  // búsqueda binaria de x en el vector arr[i..i+n]
  if (n==1) {
		if (arr[i]==x) return i; 
			else return (-1);
  }
  int k = i+(n/2);
  if (x==arr[k]) return k; 
  if (x < arr[k]) return bin_rec(arr, x, i, n/2);
      else bin_rec(arr, x, k, n-n/2);
 }


//Nota: en esta versión el arreglo puede estar ordenado o desordenado
int busca(int x, int *arr, int n) {
    for (int i=0; i<n;i++ ) {
        if (arr[i]==x) 
            return i;
    }
    return -1;
}

//Nota: asume que el arreglo está ordenado de forma ascendente
int busca_ordenado(int x, int *arr, int n) {
    for (int i=0; i<n;i++ ) {
        if (arr[i]>x)
            break;
        if (arr[i]==x) 
            return i;
    }
    return -1;
}

int busca_binaria(int x, int *arr, int n) {
    int inicio = 0;
    int fin = n-1;
    int medio; 	
    while (inicio<=fin) {
        medio = (inicio+fin)/2;
        if (arr[medio]==x)
            return medio;
        else if (arr[medio]<x)
            inicio = medio+1;
        else
            fin = medio-1;
    }
    return -1;
}

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


//Algoritmo de busqueda por interpolacion

int interpolacion(int *arr, int x, int n) {
    int inicio = 0;
    int fin = n-1;
    int medio; 	
    while (inicio<=fin) {
        medio = inicio + ((x-arr[inicio])*(fin-inicio))/(arr[fin]-arr[inicio]);
        if (arr[medio]==x)
            return medio;
        else if (arr[medio]<x)
            inicio = medio+1;
        else
            fin = medio-1;
    }
    return -1;
}

int main() {	
	int cantidad, x;
  
  cout<<"¿Cuántos números?\n";
	cin>>cantidad;
  int arr[cantidad];
  
  genera_randoms(arr,cantidad);
  insercion_directa(arr,cantidad);
  
  cout<<"El arreglo generado es: \n";
  for (int i=0;i<cantidad;i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
  
  cout<<"¿Qué numero quieres buscar?\n";
  cin >> x;
            
  // Obtener el tiempo de inicio
  auto start_time = high_resolution_clock::now();
  cout << "La busqueda lineal dice que: "<< busca(x, arr,cantidad) << endl;
  auto end_time = std::chrono::high_resolution_clock::now();
  // Calcular la duración de la ejecución
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
  cout<<" La búsqueda lineal tardó "<<duration.count()<<" microsegundos\n";
  system("pause");
  start_time = high_resolution_clock::now();
  cout <<"\nLa busqueda binaria dice que:" << busca_binaria(x,arr,cantidad) << "\n";
  end_time = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
  cout<<"La búsqueda binaria tardó "<<duration.count()<<" microsegundos\n";
  system("pause");
  
}
