#include "../../listas_t.h"
#include <iostream>

template <class T>
class Queue
{
private:
    List<T> *list;
public:
    Queue() { list = new List<T>(); };
    void enqueue(T *value) { list->add(value); };
    T *dequeue()
    {
        if (list->isEmpty())
        {
            return NULL;
        }
        T *value = list->getFirst()->getInfo();
        list->removeAt(0);
        return value;
    };
    bool isEmpty() { return list->isEmpty(); };
    ~Queue() { delete list; };
};