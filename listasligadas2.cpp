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
    virtual Nodo<T> *getFirst() const;
    virtual Nodo<T> *getLast();
    virtual void remove(T *value);
  	virtual void removeByValue(T value);
  	virtual bool removeAt(int index);
    //virtual Nodo<T> *find();  
  	virtual bool isEmpty();
    string toString() const;
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
Nodo<T> *List<T>::getFirst() const{
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

template <class T>
void List<T>::remove(T *value){
    Nodo<T> *nodo = getFirst();
    Nodo<T> *anterior = NULL;
    while (nodo != NULL) {
  		if (nodo->getInfo() == value){
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

// Elimina un valor de la lista con base al contenido del nodo (a nivel valor) 
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

// Hacer un método para eliminar el objeto que se encuentra en la posición indicada
// devolver true si existe esa posición y puede eliminar el objeto 
// falso en caso contrario.
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
    Nodo<T> *p = getFirst();
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
