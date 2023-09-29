
template <class T>

class Nodo {

    Nodo<T> *sig;
    T *info;

public:

    Nodo(T *info, Nodo<T> *sig);
    Nodo(T* info);
    virtual void setSig(Nodo<T> *sig);
    virtual void setInfo(T *info);
    virtual Nodo<T> *getSig();
    virtual T *getInfo(); //La info se retorna de tipo Gato o tipo Persona, etc...
};

template <class T>
Nodo<T>::Nodo(T *info, Nodo<T> *sig): Info(info), Sig(sig) {} //Declaracion Inline

template <class T>
Nodo<T>::Nodo(T *info) : Info(info), Sig(NULL) {}

template <class T>
void Nodo<T>::setSig(Nodo<T> *sig) {
    this->sig = sig;
}

template <class T>
void Nodo<T>::setInfo(T *info) {
    this->info = info;
}

template <class T>
Nodo<T> *Nodo<T>::getSig() {
    return sig;
}

template <class T>
T *Nodo<T>::getInfo() {
    return info;
}