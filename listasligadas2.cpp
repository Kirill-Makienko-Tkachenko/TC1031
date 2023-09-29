#include <iostream>
#include "listas_t.h"

using namespace std;

int main() {

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    Nodo<int> *p = new Nodo<int>(&arr[0]);

    Nodo<int> *inicio = p;

    for (int i = 1; i < 10; i++) {
        p=new Nodo<int>(&arr[i], p);
    }
    p=inicio;

    while (p!=NULL) {
        cout << *(p->getInfo()) << endl;
        p=p->getSig();
    }

    return 0;
}