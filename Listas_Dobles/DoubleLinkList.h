#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <string.h>
#include <sstream>
#include <iostream>
#include "Nodo.h"

using namespace std;

template <class T>
class DoubleLinkList
{  
  public:
     DoubleLinkList() {first=NULL;};
    ~ DoubleLinkList( );
    void Add(T *value);        
    bool Remove(T *value);
    bool removeAt(int index);
    virtual bool isEmpty() const;            
    virtual Nodo<T> *getFirst() const;
    virtual Nodo<T> *getLast();
    void Display(); 
    void InverseDisplay();
    void Update(int index, T *value);

  protected:
    Nodo<T> *first;
};

// Constructor

template <class T>
void DoubleLinkList<T>::Add(T *value){
  Nodo<T> *nodo = new Nodo<T>(value);
  if (first == NULL)
  {
    first = nodo;
  }
  else
  { 
  	Nodo<T> *ultimateTeam=getLast();
    ultimateTeam -> setSig(nodo);
    nodo->setAnt(ultimateTeam);
  }
}

template <class T>
bool DoubleLinkList<T>::Remove(T *value){  // if 'valor' is intended, change 'value' to 'valor'
    Nodo<T> *nodo = getFirst();
    Nodo<T> *anterior = NULL;
    int contador = 0;
    while (nodo != NULL) {
        if (*(nodo->getInfo()) == *value) {  // corrected from 'valor' to 'value', and dereferencing pointer for comparison
            std::cout << "Se encontro el valor en el indice: " << contador << std::endl;
            if (anterior == NULL) {
                first = nodo->getSig();
                if (first != NULL) {  // added check for NULL
                    first->setAnt(NULL);
                }
            } else {
                anterior->setSig(nodo->getSig());
                if (nodo->getSig() != NULL) {
                    nodo->getSig()->setAnt(anterior);
                }
            }
            delete nodo;
            return true;
        }
        contador++;
        anterior = nodo;
        nodo = nodo->getSig();
    }
    return false;
}

template <class T>
bool DoubleLinkList<T>::removeAt(int index) {
    Nodo<T> *nodo = getFirst();
    Nodo<T> *anterior = NULL;
    int contador = 0;
    while (nodo != NULL) {
        if (contador == index) {
            if (anterior == NULL) {
                first = nodo->getSig();
                first -> setAnt(NULL);
            } else {
                anterior->setSig(nodo->getSig());
                if (nodo->getSig() != NULL) {
                    // If there is a next node, update its previous pointer
                    nodo->getSig()->setAnt(anterior);
                }
            }
            delete nodo;
            return true;
        }
        contador++;
        anterior = nodo;
        nodo = nodo->getSig();
    }
    return false;
}


template <class T>
Nodo<T> *DoubleLinkList<T>::getFirst() const{
	return first;
}  

template <class T>
bool DoubleLinkList<T>::isEmpty() const {
  return first==NULL;
}


template <class T>
Nodo<T> *DoubleLinkList<T>::getLast() {
    if (isEmpty()) return NULL;
    Nodo<T> *p = first;
    while (p->getSig() != NULL) {
        p = p->getSig();
    }
    return p;
}

template <class T>
void DoubleLinkList<T>::Update(int index, T *value){

    Nodo<T> *nodo = getFirst();
    Nodo<T> *anterior = NULL;
    int contador = 0;
    while (nodo != NULL) {
        
        if (contador == index){
            nodo->setInfo(value);
        } 
        }
        contador++;
        anterior = nodo;
        nodo = nodo->getSig();
}



template <class T>
void DoubleLinkList<T>::Display() {
    Nodo<T> *p = getFirst();
    string outputStr = "";
    while (p != NULL) {
        stringstream ss;
        ss << *(p->getInfo());
        outputStr += ss.str() + " ";
        p = p->getSig();
    }
    cout << outputStr << endl;
}

template <class T>  
void DoubleLinkList<T>::InverseDisplay() {
    Nodo<T> *p = getLast();
    while(p != getFirst()) {
        cout << *(p->getInfo()) << " ";
        p = p->getAnt();
    }
    cout << *(p->getInfo()) << endl;
}

#endif