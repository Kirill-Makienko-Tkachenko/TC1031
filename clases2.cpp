#include <iostream>
#include <random>

using namespace std;

class Dado {
    private:
        int resultado;
    public:
        Dado();
        Dado(int res);
        Dado(bool aleatorio);
        int dameResultado(){return resultado;};
};

int genera_aleatorio() {
    std::random_device rd;   // Obtener una semilla aleatoria del dispositivo
    std::mt19937 gen(rd());  // Inicializar el generador con la semilla
    std::uniform_int_distribution<> distribucion(1, 6);   
    return distribucion(gen); 
}

Dado::Dado() {
    resultado = -1;
}
Dado::Dado(int res){
    resultado=res;
}
Dado::Dado(bool aleatorio) {
    if (aleatorio) {
        resultado=genera_aleatorio();
    }
}


int main(){

    Dado dadito = Dado();

    cout << "El resultado es:  " << dadito.dameResultado() << endl;




    return 0;
}
