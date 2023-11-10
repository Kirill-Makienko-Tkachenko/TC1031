#include <string.h>
#include <sstream>

using namespace std;

template <class T>
class Nodo {
    public: 
        Nodo(T *info, Nodo<T> *sig);
        Nodo(T *info);
        virtual void setSig(Nodo<T> *sig);
        virtual void setInfo(T *info);
        virtual Nodo<T> *getSig();
        virtual T *getInfo();
    private:
        Nodo<T> *Sig;
        T *Info;
};

template <class T>
Nodo<T>::Nodo(T *info, Nodo<T> *sig):Info(info), Sig(sig) {}

template <class T>
Nodo<T>::Nodo(T *info) { Sig=NULL; Info=info; }

template <class T>
void Nodo<T>::setSig(Nodo<T> *sig){Sig=sig;};

template <class T>
void Nodo<T>::setInfo(T *info) {Info=info; };

template <class T>
Nodo<T> *Nodo<T>::getSig(){return Sig;};

template <class T>
T *Nodo<T>::getInfo(){return Info;};

// CLASE LIST

template <class T>
class List{
public:
    List(){first=NULL;}
    virtual void add(T *value);
    virtual Nodo<T> *getFirst();
    virtual Nodo<T> *getLast();
    virtual void removeByValue(T value);
    virtual bool removeAt(int index);
    //virtual Nodo<T> *find();
    virtual bool isEmpty();
    string toString() const;
    bool find(T *value);
private:
    Nodo<T> *first;
};

template <class T>
void List<T>::add(T *value){
    Nodo<T> *nodo = new Nodo<T>(value);
    if (first == NULL)
    {
        first = nodo;
    }
    else
    {
        Nodo<T> *ultimateTeam=getLast();
        ultimateTeam -> setSig(nodo);
    }
}


template <class T>
Nodo<T> *List<T>::getFirst(){
    return first;
}

template <class T>
bool List<T>::isEmpty(){
    return first==NULL;
}

template <class T>
Nodo<T> *List<T>::getLast() {
    if (isEmpty()) return NULL;

    Nodo<T> *p = first;
    while (p-> getSig()!=NULL){
        p = p -> getSig();
    }
    return p;
}

// Elimina un valor de la lista con base al contenido al nodo
template <class T>
void List<T>::removeByValue(T value){
    Nodo<T> *nodo = getFirst();
    Nodo<T> *anterior = NULL;
    while (nodo != NULL) {
        if (*(nodo->getInfo()) == value){
            if (anterior == NULL){
                first = nodo->getSig();
            } else {
                anterior->setSig(nodo->getSig());
            }
            delete nodo;
            return;
        }
        anterior = nodo;
        nodo = nodo->getSig();
    }
}

template <class T>
bool List<T>::removeAt(int index){
    Nodo<T> *nodo = getFirst();
    Nodo<T> *anterior = NULL;
    int contador = 0;
    while (nodo != NULL) {
        if (contador == index){
            if (anterior == NULL){
                first = nodo->getSig();
            } else {
                anterior->setSig(nodo->getSig());
            }
            delete nodo;
            return true;
        }
        contador ++;
        anterior = nodo;
        nodo = nodo->getSig();
    }
    return false;
}

template <class T>
string List<T>::toString() const {
    Nodo<int> *p = getFirst();
    string outputStr="";
    while (p!=NULL)
    {
        stringstream ss;
        ss<<*(p->getInfo());
        outputStr+=ss.str()+" ";
        p=p->getSig();
    }
    return outputStr;
}

template <class T>
ostream& operator<< ( ostream& outs, const List<T>* obj ) {
    return outs << obj->toString();
}

template <class T>
bool operator==(const List<T>& list1, const List<T>& list2) {
    Nodo<T>* current1 = list1.getFirst();
    Nodo<T>* current2 = list2.getFirst();

    while (current1 != NULL && current2 != NULL) {
        if (*(current1->getInfo()) != *(current2->getInfo())) {
            return false;
        }
        current1 = current1->getSig();
        current2 = current2->getSig();
    }

    return (current1 == NULL && current2 == NULL);
}


template <class T>
bool List<T>::find(T *value){
  Nodo<T> *nodo = getFirst();
  Nodo<T> *anterior = NULL;
  while (nodo != NULL) {
  	if (nodo->getInfo() == value){
          return true;	
    }
    anterior = nodo;
    nodo = nodo->getSig();
  }
  return false;
}
