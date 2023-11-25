#include "splay_trees.h"
#include <iostream>

using namespace std;

int main() {
    //int arr[] {20,1,4,7,23,5,10,8,11,21};
    int arr[] {13,7,9,11,23,3,6,2,28,4,8,1,19};

    SplayTree<int> *arbolito=new SplayTree<int>();

    for (int i=0; i<13;i++) {
        arbolito->addValue(&arr[i]);
    }

  	cout<<"Valores del arbol:";
  	arbolito->display();  
    
  	int val=0;
    do {
  		cout<<endl<<"Que valor quieres buscar?";
      cin>>val;
      arbolito->findValue(&val);
      cout<<"Árbol:";	
      arbolito->display();  
    } while (val!=0);

    cout<<"Quedaron "<<arbolito->count()<<" nodos en el árbol.";

}
//c
