#include "bin_trees.h"
#include <iostream>

using namespace std;

int main() {
    int arr[] {13,7,9,11,23,3,6,2,23,28,4,8,1,19};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    BST<int> *arbolito = new BST<int>();

    for (int i = 0; i < arrSize; i++) {
        arbolito->addValue(&arr[i]);
    }

    cout << "Valores del arbol:";
    arbolito->display();

    int val = 0;
    do {
        cout << endl << "Que valor quieres eliminar? ";
        cin >> val;

        // Verifica que val sea un valor válido
        if (val != 0) {
            arbolito->removeValue(&val);
            cout << "Nuevo arbol:";
            arbolito->display();
        }
    } while (val != 0);

    cout << "Recorriendo a la anchura " << endl;



    delete arbolito; // No olvides liberar la memoria del árbol antes de salir

    return 0;
}


