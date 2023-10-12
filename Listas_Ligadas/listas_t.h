#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

// Nodo class definition
template <class T>
class Nodo {
public: 
    // O(1) - Constante
    Nodo(T *info, Nodo<T> *sig) : Info(info), Sig(sig) {}
    // O(1) - Constante
    Nodo(T *info) : Sig(NULL), Info(info) {}
    // O(1) - Constante
    virtual void setSig(Nodo<T> *sig) { Sig = sig; }
    // O(1) - Constante
    virtual void setInfo(T *info) { Info = info; }
    // O(1) - Constante
    virtual Nodo<T> *getSig() { return Sig; }
    // O(1) - Constante
    virtual T *getInfo() { return Info; }
private:
    Nodo<T> *Sig;
    T *Info;
};

// List class definition
template <class T>
class List {
public:
    // O(1) - Constante
    List() : first(NULL) {}
    // O(n) - Lineal (en el peor caso)
    virtual void add(T *value);
    // O(1) - Constante
    virtual Nodo<T> *getFirst();
    // O(n) - Lineal (en el peor caso)
    virtual Nodo<T> *getLast();
    // O(n) - Lineal (en el peor caso)
    virtual bool removeAt(int index);
    // O(1) - Constante
    virtual bool isEmpty();
    // O(n) - Lineal
    string toString() const;
private:
    Nodo<T> *first;
};

template <class T>
void List<T>::add(T *value) {
    Nodo<T> *nodo = new Nodo<T>(value);
    if (first == NULL) {
        first = nodo;
    } else {
        Nodo<T> *ultimateTeam = getLast();
        ultimateTeam->setSig(nodo);
    }
}

template <class T>
Nodo<T> *List<T>::getFirst() {
    return first;
}

template <class T>
bool List<T>::isEmpty() {
    return first == NULL;
}

template <class T>
Nodo<T> *List<T>::getLast() {
    if (isEmpty()) return NULL;
    Nodo<T> *p = first;
    while (p->getSig() != NULL) {
        p = p->getSig();
    }
    return p;
}

template <class T>
bool List<T>::removeAt(int index) {
    Nodo<T> *nodo = getFirst();
    Nodo<T> *anterior = NULL;
    int contador = 0;
    while (nodo != NULL) {
        if (contador == index) {
            if (anterior == NULL) {
                first = nodo->getSig();
            } else {
                anterior->setSig(nodo->getSig());
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
string List<T>::toString() const {
    Nodo<T> *p = getFirst();
    string outputStr = "";
    while (p != NULL) {
        stringstream ss;
        ss << *(p->getInfo());
        outputStr += ss.str() + " ";
        p = p->getSig();
    }
    return outputStr;
}

// O(n) - Lineal
template <class T>
ostream& operator<< (ostream& outs, const List<T>& obj) {
    return outs << obj.toString();
}
