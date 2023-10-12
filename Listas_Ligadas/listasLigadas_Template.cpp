
#include <iostream>
#include "listas_t.h"
#include "Contacto.h"
#include "Direccion.h"

using namespace std;

int main()
{

    List<Contacto> *listita = new List<Contacto>();
    int opcion = 0;
    while (opcion != 4)
    {
        cout << "Seleccione que desea hacer: " << endl;
        cout << "1. Crear un contacto" << endl;
        cout << "2. Eliminar un contacto" << endl;
        cout << "3. Buscar un contacto" << endl;
        cout << "4. Salir" << endl;

        cin >> opcion;

        if (opcion == 1)
        {
            cout << "Ingrese el nombre del contacto: " << endl;
            string nombre;
            cin >> nombre;
            cout << "Ingrese el numero del contacto: " << endl;
            int numero;
            cin >> numero;
            cout << "Ingrese la direccion del contacto: " << endl;
            string direccion;
            cin >> direccion;
            cout << "Ingrese la ciudad del contacto: " << endl;
            string ciudad;
            cin >> ciudad;
            cout << "Ingrese el estado del contacto: " << endl;
            string estado;
            cin >> estado;

            Direccion *dir = new Direccion(numero, ciudad, estado, direccion);
            Contacto *contacto = new Contacto(numero, *dir, nombre);
            listita->add(contacto);
        }

        if (opcion == 2)
        {
            cout << "Ingrese el numero de contacto que desea eliminar: " << endl;
            int numero;
            cin >> numero;
            listita->removeAt(numero);
        }

        if (opcion == 3)
        {
            cout << "Ingrese el numero de contacto que desea buscar: " << endl;
            int numero;
            cin >> numero;
            Nodo<Contacto> *nodo = listita->getFirst();
            while (nodo != NULL)
            {
                if (nodo->getInfo()->getNumero() == numero)
                {
                    cout << "Nombre: " << nodo->getInfo()->getNombre() << endl;
                    cout << "Numero: " << nodo->getInfo()->getNumero() << endl;
                    cout << "Direccion: " << nodo->getInfo()->getDireccion().getCalle() << endl;
                    cout << "Ciudad: " << nodo->getInfo()->getDireccion().getMunicipio() << endl;
                    cout << "Estado: " << nodo->getInfo()->getDireccion().getEstado() << endl;
                }
                nodo = nodo->getSig();
            }
        }
    }

    return 0;
}
