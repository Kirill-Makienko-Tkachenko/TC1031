#ifndef NODE_H
#define NODE_H

#include <string.h>
#include <sstream>

using namespace std;


template <class T>
class Nodo {
    public: 
        Nodo(T *info, Nodo<T> *sig, Nodo<T> *ant);
        Nodo(T *info);
        Nodo();
        virtual void setSig(Nodo<T> *sig);
        virtual Nodo<T> *getSig();
        virtual void setAnt(Nodo<T> *ant);
        virtual Nodo<T> *getAnt();
        virtual void setInfo(T *info);
        virtual T *getInfo();
    private:
        Nodo<T> *Sig;
        Nodo<T> *Ant;
        T *Info;
};

//Constructors
template <class T>
Nodo<T>::Nodo(T *info, Nodo<T> *sig, Nodo<T> *ant): Info(info), Sig(sig), Ant(ant) {}

template <class T>
Nodo<T>::Nodo(T *info) { Sig=NULL; Info=info; }

template <class T>
Nodo<T>::Nodo() { Sig=NULL; Info=NULL; Ant=NULL; }

//Setters
template <class T>
void Nodo<T>::setSig(Nodo<T> *sig){Sig=sig;};

template <class T>
void Nodo<T>::setAnt(Nodo<T> *ant) {Ant=ant;};

template <class T>
void Nodo<T>::setInfo(T *info) { Info=info; };

//Getters

template <class T>
Nodo<T> *Nodo<T>::getSig(){return Sig;};

template <class T>
T *Nodo<T>::getInfo(){return Info;};

template <class T>
Nodo<T> *Nodo<T>::getAnt(){return Ant;}

#endif