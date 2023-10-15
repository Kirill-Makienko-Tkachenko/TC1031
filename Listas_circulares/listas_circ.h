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

// CLASE CList
template <class T>
class CList
{
public:
    CList() { first=NULL; };
    virtual void add(T *value);
    virtual bool isEmpty() const;
    virtual Nodo<T> *getFirst() const;
    virtual Nodo<T> *getLast();
    virtual void remove(T *value);
    virtual bool removeAt(int index);
    string toString() const;
private:
    Nodo<T> *first;
};

template <class T>
void CList<T>::add(T *value)
{ // CAMBIÓ
    Nodo<T> *nodo = new Nodo<T>(value);
    if (first == NULL)
    {
        first = nodo;
    }
    else
    {
        Nodo<T> *ultimate = getLast();
        ultimate->setSig(nodo);
    }
    nodo->setSig(first);
}

template <class T>
Nodo<T> *CList<T>::getFirst() const{
	return first;
}  

template <class T>
bool CList<T>::isEmpty() const {
  return first==NULL;
}


template <class T>
Nodo<T> *CList<T>::getLast()
{ // CAMBIÓ
    if (isEmpty())
        return NULL;

    Nodo<T> *p = first;
    while (p->getSig() != first)
    {
        p = p->getSig();
    }
    return p;
}

template <class T>
void CList<T>::remove(T *value)
{ // CAMBIÓ

    if (isEmpty ())
        return;

    Nodo<T> *nodo = getFirst();
    Nodo<T> *anterior = NULL;

    if ((nodo->getSig() == nodo) && (nodo->getInfo() == value))
    {
        delete nodo;
        first = NULL;
        return;
    }

    do
    {
        if (nodo->getInfo() == value)
        {
            if (anterior == NULL)
            {
                Nodo<T> *ultimo = getLast();
                first = nodo->getSig();
                ultimo->setSig(first);
            }
            else
            {
                anterior->setSig(nodo->getSig());
            }
            delete nodo;
            return;
        }
        anterior = nodo;
        nodo = nodo->getSig();
    } while (nodo != first);
}

// Hacer un método para eliminar el objeto que se encuentra en la posición indicada
// devolver true si existe esa posición y puede eliminar el objeto
// falso en caso contrario.
template <class T>
bool CList<T>::removeAt(int index)  // CAMBIÓ
{
    if (isEmpty ())
        return false;

    Nodo<T> *nodo = getFirst();
    Nodo<T> *anterior = NULL;
    int contador = 0;

    if ((nodo->getSig() == nodo) && (index==0))
    {
        delete nodo;
        first = NULL;
        return true;
    }

    do
    {
        if (contador == index)
        {
            if (anterior == NULL)
            {
                Nodo<T> *ultimo = getLast();
                first = nodo->getSig();
                ultimo->setSig(first);
            }
            else
            {
                anterior->setSig(nodo->getSig());
            }
            delete nodo;
            return true;
        }
        contador++;
        anterior = nodo;
        nodo = nodo->getSig();
    } while (nodo != first);

    return false;
}

template <class T>
string CList<T>::toString() const   // CAMBIÓ
{
    Nodo<T> *p = getFirst();
    string outputStr = "";

    if (isEmpty()==true)
        return outputStr;

    do
    {
        stringstream ss;
        ss << *(p->getInfo());
        outputStr += ss.str() + " ";
        p = p->getSig();
    } while (p != first);

    return outputStr;
}

template <class T>
ostream &operator<<(ostream &outs, const CList<T> *obj)
{
    return outs << obj->toString();
}

