#include<iostream>
#include<vector>
#include<cstring>
#include<utility> // for pair

using namespace std;

class Vendedor{
    double totalVentas;
    char nombre[100];
    vector<pair<string, double>> VENTAS; // holds the month and the corresponding total sales
public:
    //setters
    void setNombre(const char* nombre) { strcpy(this -> nombre, nombre); }
    void setVentaMes(const string& mes, double ventas) {
        VENTAS.push_back({mes, ventas});
    }

    //getters
    const char* getNombre() const { return nombre; }
    double getVentaMes(const string& mes) const {
        for(const auto& venta : VENTAS)
            if(venta.first == mes) return venta.second;
        return 0.0; // or another suitable value if the month is not found
    }
    double getTotalVentas(){ 
    auto total = 0.0; 
    for(const auto& venta : VENTAS){
        total += venta.second; 
    }
    return total;
    }
    double getMesVentas(char mes[100]){
        for(const auto& venta : VENTAS)
            if(venta.first == mes) return venta.second;
        return 0.0; // or another suitable value if the month is not found
    }

    Vendedor(){ 

    for(int i=0; i <= 12; i++){
        VENTAS.push_back({"", 0.0});
    }

    }

};

desplegar


int main(){

    Vendedor vendedor;
    vendedor.setNombre("No se me ocurrio un nombre xd");
    vendedor.setVentaMes("Enero", 1000.0);
    vendedor.setVentaMes("Febrero", 2000.0);
    vendedor.setVentaMes("Marzo", 3000.0);
    vendedor.setVentaMes("Abril", 4000.0);
    vendedor.setVentaMes("Mayo", 5000.0);
    vendedor.setVentaMes("Junio", 6000.0);
    vendedor.setVentaMes("Julio", 7000.0);
    vendedor.setVentaMes("Agosto", 8000.0);
    vendedor.setVentaMes("Septiembre", 9000.0);
    vendedor.setVentaMes("Octubre", 10000.0);
    vendedor.setVentaMes("Noviembre", 11000.0);
    vendedor.setVentaMes("Diciembre", 12000.0);

    cout << "El vendedor " << vendedor.getNombre() << " vendio en total " << vendedor.getTotalVentas() << endl;

    cout << "El vendedor " << vendedor.getNombre() << " vendio en Enero " << vendedor.getVentaMes("Enero") << endl;

    return 0;
}
