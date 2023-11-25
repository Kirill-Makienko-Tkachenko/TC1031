#include <iostream>
#include <sstream>

using namespace std;

// Nodo class definition
template <class T, class U>
class Nodo {
public:
    Nodo(T info, U info2, Nodo<T, U>* sig) : Info(info), Info2(info2), Sig(sig) {}

    // Getter and setter methods for Info and Info2
    T getInfo() { return Info; }
    void setInfo(T info) { Info = info; }

    U getInfo2() { return Info2; }
    void setInfo2(U info2) { Info2 = info2; }

    Nodo<T, U>* getSig() { return Sig; }
    void setSig(Nodo<T, U>* sig) { Sig = sig; }

private:
    Nodo<T, U>* Sig;
    T Info;
    U Info2;
};

// List class definition
template <class T, class U>
class List {
public:
    List() : first(nullptr) {}

    void add(T info, U info2);
    Nodo<T, U>* getFirst();
    Nodo<T, U>* getLast();
    bool removeAt(int index);
    bool isEmpty();
    string toString() const;

    bool find(T info);

private:
    Nodo<T, U>* first;
};

template <class T, class U>
void List<T, U>::add(T info, U info2) {
    Nodo<T, U>* nodo = new Nodo<T, U>(info, info2, nullptr);
    if (first == nullptr) {
        first = nodo;
    } else {
        Nodo<T, U>* ultimateTeam = getLast();
        ultimateTeam->setSig(nodo);
    }
}

template <class T, class U>
Nodo<T, U>* List<T, U>::getFirst() {
    return first;
}

template <class T, class U>
bool List<T, U>::isEmpty() {
    return first == nullptr;
}

template <class T, class U>
Nodo<T, U>* List<T, U>::getLast() {
    if (isEmpty()) return nullptr;
    Nodo<T, U>* p = first;
    while (p->getSig() != nullptr) {
        p = p->getSig();
    }
    return p;
}

template <class T, class U>
bool List<T, U>::removeAt(int index) {
    Nodo<T, U>* nodo = getFirst();
    Nodo<T, U>* anterior = nullptr;
    int contador = 0;
    while (nodo != nullptr) {
        if (contador == index) {
            if (anterior == nullptr) {
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

template <class T, class U>
string List<T, U>::toString() const {
    Nodo<T, U>* p = getFirst();
    stringstream ss;
    while (p != nullptr) {
        ss << p->getInfo() << " " << p->getInfo2() << " ";
        p = p->getSig();
    }
    return ss.str();
}

template <class T, class U>
bool List<T, U>::find(T info) {
    Nodo<T, U>* nodo = getFirst();
    while (nodo != nullptr) {
        if (nodo->getInfo() == info) {
            return true;
        }
        nodo = nodo->getSig();
    }
    return false;
}
