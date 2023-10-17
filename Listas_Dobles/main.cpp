#include<iostream>
#include<time.h>
#include "DoubleLinkList.h"
#include "Nodo.h"

using namespace std;

int main() {

    srand(time(NULL));

    DoubleLinkList<int> *dblist = new DoubleLinkList<int>();

    int randoms[20];

    for (int i = 0; i < 20; i++) {
        randoms[i] = (rand() % 100);
        dblist->Add(&randoms[i]);
    }

    dblist->Display();
    dblist->InverseDisplay();

    cout << "Que valor deseas eliminar?" << endl;
    int valor;
    cin >> valor;
    dblist->Remove(&valor);

    dblist->Display();
    dblist->InverseDisplay();

    cout << "Que valor deseas agregar?" << endl;
    cin >> valor;
    dblist->Add(&valor);

    dblist->Display();
    dblist->InverseDisplay();



    return 0;
}