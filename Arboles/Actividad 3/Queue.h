#include "listas_t.h"

template <class T>
class Queue
{

    list<T> *list;

public:
    Queue() { list = new list<T>(); };
    void enqueue(T *value) { list->add(value); };
    T *dequeue()
    {
        if (list->isEmpty())
            return NULL;
        T *val = list->getFirst()->getInfo();
        list->removeAt(0);
        return val;
    };
    ~Queue() { delete *list; }
};