
#include <iostream>
#include "listas_t.h"

using namespace std;

int main() {
    int arr[] = {10, 12,1,45,12};

    List<int> *listita = new List<int>();

    for (int i=0;i<5;i++) {
        listita->add(&arr[i]);
    }

    Nodo<int> *p = listita->getFirst();
    while (p!=NULL){
        cout<<*(p->getInfo())<<endl;
        p=p->getSig();
    }
}

