#ifndef DIRECCION_H
#define DIRECCION_H

#include <iostream>
#include <string>

using namespace std;

class Direccion
{
    string calle, municipio, estado;
    int numero;

public:
    Direccion(int num,
              string muni,
              string est,
              string cal)
        : numero(num), municipio(muni), estado(est), calle(cal) {}
    ~Direccion() {}

    void setNumero(int num) { numero = num; }
    void setMunicipio(string muni) { municipio = muni; }
    void setEstado(string est) { estado = est; }
    void setCalle(string cal) { calle = cal; }

    int getNumero() { return numero; }
    string getMunicipio() { return municipio; }
    string getEstado() { return estado; }
    string getCalle() { return calle; }
    
    void print() {
        cout << "Calle: " << calle << endl;
        cout << "Numero: " << numero << endl;
        cout << "Municipio: " << municipio << endl;
        cout << "Estado: " << estado << endl;
    }

    ostream &operator<<(ostream &os)
    {
        os << "Calle: " << calle << endl;
        os << "Numero: " << numero << endl;
        os << "Municipio: " << municipio << endl;
        os << "Estado: " << estado << endl;
        return os;
    }
};

#endif // DIRECCION_H

