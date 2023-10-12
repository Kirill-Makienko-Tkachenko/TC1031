#include "Direccion.h"
#include <iostream>

using namespace std;

class Contacto {

    string nombre;
    int numero;
    Direccion direccion;
public:
    Contacto(int num, Direccion dir, string nom) : nombre(nom), numero(num), direccion(dir) {}
    int getNumero() const { return numero; }
    string getNombre() const { return nombre; }
    void setNombre(string nom) { nombre = nom; }
    void setNumero(int num) { numero = num; }
    void setDireccion(Direccion dir) { direccion = dir; }
    Direccion getDireccion() const { return direccion; }
    void print() {
        cout << "Nombre: " << nombre << endl;
        cout << "Numero: " << numero << endl;
        direccion.print();
    }
};
