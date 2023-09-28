// Kirill Makienko Tkachenko

#include <iostream>
using namespace std;

// Declaración de funciones
int sumaIterativa(int n);
int sumaRecursiva(int n);
int sumaDirecta(int n);

int main() {
    // Este programa demuestra tres métodos para sumar números del 1 al n:
    // suma iterativa, suma recursiva y suma mediante fórmula directa.

    int n;
    cout << "Ingrese un número: "; // Solicita al usuario ingresar un número
    cin >> n; // Lee el número ingresado

    // Calcula y muestra la suma utilizando el método iterativo
    cout << "La suma iterativa de 1 hasta mediante el método de suma iterativa de " << n << " es: " << sumaIterativa(n) << endl;

    // Calcula y muestra la suma utilizando el método recursivo
    cout << "La suma recursiva de 1 hasta mediante el método de suma recursiva de " << n << " es: " << sumaRecursiva(n) << endl;

    // Calcula y muestra la suma utilizando la fórmula directa
    cout << "La suma directa de 1 hasta mediante el método de suma directa de " << n << " es: " << sumaDirecta(n) << endl;
}

// Función para calcular la suma utilizando el método iterativo
int sumaIterativa(int n) {
    int suma = 0; // Inicializa una variable para almacenar la suma
    for (int i = 1; i <= n; i++) {
        suma += i; // Agrega cada número del 1 al n a la suma
    }
    return suma; // Devuelve la suma calculada
}

// Función para calcular la suma utilizando el método recursivo
int sumaRecursiva(int n) {
    if (n <= 0) {
        return 0; // Devuelve 0 si n es negativo o 0
    } else if (n == 1) {
        return 1; // Devuelve 1 si n es 1
    } else {
        // Devuelve la suma de n y la suma de los números del 1 al n-1 (de manera recursiva)
        return n + sumaRecursiva(n - 1);
    }
}

// Función para calcular la suma utilizando la fórmula directa
int sumaDirecta(int n) {
    return (n * (n + 1)) / 2; // Devuelve la suma utilizando la fórmula directa (suma de una serie aritmética)
}
