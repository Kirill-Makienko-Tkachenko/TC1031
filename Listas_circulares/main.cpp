#include <iostream>
#include "listas_circ.h"

using namespace std;

int main() {
   
    /*
     CList<int> *lista_c=new CList<int>();
    int arr[]={1,2,3};
    lista_c->add(&arr[0]);
    lista_c->add(&arr[1]);
    lista_c->add(&arr[2]);
    cout<<lista_c;
    lista_c->removeAt(1);
    cout<<lista_c;
    */

   string estaciones[] {"Primavera","Verano","Otoño","Invierno"};
   CList<string> *lista_c=new CList<string>();

    for (int i=0;i<4;i++)
        lista_c->add(&estaciones[i]);

    Nodo<string> *nodo=lista_c->getFirst();
    
    char c;
    do {
        cout<<*(nodo->getInfo());
        char c=cin.get();
        nodo=nodo->getSig();
    }  while (c!='s');

}