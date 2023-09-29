#include <iostream>

using namespace std;

class Nodo {
    public:
        Nodo(int valor) {this->info=valor; sig=NULL; }
        Nodo() { sig=NULL; }
        int info;
        Nodo *sig=NULL;
};

class List {
    public:
        bool AcceptDuplicates;

        List() { AcceptDuplicates=true; inicio=NULL; };
        void add(int valor);
        void remove(int valor);
        bool esta_vacia();
        Nodo *GetLast();
        void desplegarLista();
        // métodos de tarea
        Nodo *GetFirst();
        Nodo *find(int valor);
        int Count();
        ~List();
    private:
        Nodo *inicio;

};

void List::add(int valor) {
    Nodo *nodo=new Nodo(valor);
    if (inicio==NULL) {
        inicio=nodo;
    } else {
				Nodo *ultimo=GetLast();
        if (AcceptDuplicates){
          Nodo *exists = find(valor);
          if(exists == NULL){
      			ultimo->sig=nodo;
          }
        } else {
      			ultimo->sig=nodo;
        }
    }
}

bool List::esta_vacia(){
  return inicio==NULL;
}

Nodo *List::GetLast() {
  if (esta_vacia()) return NULL;
  
  Nodo *p = inicio; 
  while (p-> sig!=NULL){
    p = p -> sig;
  }
  return p;
}

void List::desplegarLista(){  
  Nodo *p = inicio; 
  while (p!=NULL){
    cout << p -> info<< " ";
    p=p->sig;
  }
  cout<<"\n";  
}

//**** Métodos de tarea******/

Nodo *List::GetFirst() {
  return inicio;
}

List::~List() {
 	    Nodo *nodo=GetFirst();
      Nodo *nodoSig;
      while (nodo!=NULL) {
	      nodoSig=nodo->sig;
        delete nodo;
        nodo=nodoSig;
      }    
}

Nodo *List::find(int valor) {
	Nodo *p = GetFirst();
  while (p != NULL){
    if (p -> info == valor){
      break;
    }
    else{
      p = p ->sig; 
    } 
  }
  return p;
}

int List::Count(){
  Nodo *p = GetFirst();
  int contador = 0;
  while (p != NULL){
		contador = contador + 1;
    p = p ->sig; 
  }
  return contador;
}
