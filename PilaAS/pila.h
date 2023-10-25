#include <iostream>
#include "listas_t.h"

using namespace std;

template <class T>
class TStack { 
  private:
  	List<T> *lista;
    int size;		
  public:
  	TStack() { lista = new List<T>(); size = 0; }
    virtual bool empty();
  	virtual T *pop();
    virtual void push(T *val);
    virtual T *stacktop();
};

template <class T>
bool TStack<T>::empty() {
	return lista->isEmpty();
}

template <class T>                          
T *TStack<T>::pop(){						
	if (lista->isEmpty()) return NULL;       
  T *elem = lista->getLast()->getInfo();				
  lista->removeAt(--size);					
  return elem;
}

template <class T>
void TStack<T>::push(T *val) {
	lista->add(val);
  size++;
}

template <class T>
T *TStack<T>::stacktop() {
	if (lista->isEmpty()) return NULL;
  return lista->getLast()->getInfo();
}
