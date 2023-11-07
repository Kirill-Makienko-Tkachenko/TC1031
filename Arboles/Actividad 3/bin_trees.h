#include <iostream>
#include "queue.h"

using namespace std;

template <class T>
class TreeNode
{
private:
    T *value;
    TreeNode<T> *leftNode;
    TreeNode<T> *rightNode;
public:
    TreeNode<T>()
    {
        leftNode = NULL;
        rightNode = NULL;
    }
    TreeNode<T>(T *pValue)
    {
        value = pValue;
        leftNode = NULL;
        rightNode = NULL;
    }
    TreeNode<T>(T *pValue, TreeNode<T> *pLeftNode, TreeNode<T> *pRightNode)
    {
        value = pValue;
        leftNode = pLeftNode;
        rightNode = pRightNode;
    }
    TreeNode<T> *getLeftNode() { return leftNode; }
    TreeNode<T> *getRightNode() { return rightNode; }
    void setLeftNode(TreeNode<T> *pLeftNode) { leftNode = pLeftNode; }
    void setRightNode(TreeNode<T> *pRightNode) { rightNode = pRightNode; }
    T *getValue() { return value; }
    void setValue(T *pValue) { value = pValue; }
};

template <class T>
class BST
{
private:
    TreeNode<T> *rootNode;
    List<T> *markedNodes;
    Queue<TreeNode<T> *> *queue;
    void privBFS(TreeNode<T> *node);
public:
    BST<T>() { rootNode = NULL; markedNodes=NULL; queue = NULL; }
    bool addValue(T *value);
    bool findValue(T *value);
    bool removeValue(T *value);
    int compareNodeValues(T *v1, T *v2);
    void display();
    void InOrder(TreeNode<T> *node);
    // nuevos
    int count();
    int count_rec(TreeNode<T> *node);
  	void BFS();
};

template <class T>
int BST<T>::compareNodeValues(T *v1, T *v2)
{
    if (*v1 == *v2)
    {
        return 0;
    }
    if (*v1 > *v2)
    {
        return 1;
    }
    else
        return -1;
}

template <class T>
bool BST<T>::addValue(T *value)
{
    TreeNode<T> *newNode, *prevNode = NULL, *currentNode = rootNode;
    while (currentNode != NULL)
    {
        if (compareNodeValues(value, currentNode->getValue()) == 0)
            return false;
        prevNode = currentNode;
        currentNode = (compareNodeValues(value, currentNode->getValue()) == 1 ? currentNode->getRightNode() : currentNode->getLeftNode());
    }
    // si llego aqui se inserta
    newNode = new TreeNode<T>(value);
    if (prevNode == NULL)
        rootNode = newNode;
    else
    {
        if (compareNodeValues(value, prevNode->getValue()) == 1)
            prevNode->setRightNode(newNode);
        else
            prevNode->setLeftNode(newNode);
    }
    return true;
}

template <class T>
bool BST<T>::findValue(T *value)
{
    TreeNode<T> *newNode, *currentNode = rootNode;
    while (currentNode != NULL)
    {
        if (compareNodeValues(value, currentNode->getValue()) == 0)
            return true;
        currentNode = (compareNodeValues(value, currentNode) == 1 ? currentNode->getRightNode() : currentNode->getLeftNode());
    }
    return false;
}

template <class T>
void BST<T>::display()
{
    InOrder(rootNode);
}

template <class T>
void BST<T>::InOrder(TreeNode<T> *node)
{
    if (node == NULL)
        return;
    InOrder(node->getLeftNode());
    cout << *(node->getValue()) << " ";
    InOrder(node->getRightNode());
}

template <class T>
bool BST<T>::removeValue(T *value)
{
    TreeNode<T> *newNode, *prevNode = NULL, *currentNode = rootNode;
    while (currentNode != NULL)
    {
        if (compareNodeValues(value, currentNode->getValue()) == 0)
        {   // ya lo encontramos
            // es un nodo hoja
            if (currentNode->getLeftNode() == NULL && currentNode->getRightNode() == NULL)
            {
                if (prevNode != NULL)
                { // No es el nodo raiz
                    if (currentNode == prevNode->getLeftNode())
                        prevNode->setLeftNode(NULL);
                    if (currentNode == prevNode->getRightNode())
                        prevNode->setRightNode(NULL);
                }
                else // es el nodo raiz
                    rootNode = NULL;
                delete currentNode;
                return true;
            }
            // es un nodo con dos hijos
            if (currentNode->getLeftNode() != NULL && currentNode->getRightNode() != NULL)
            {
                cout<<"Nodo con dos hijos"<<endl;
                // en busca del predecesor, se mueve a la izquierda del nodo actual
                TreeNode<T> *prevP = currentNode; // Estaba como NULL y después de la siguiente línea
                TreeNode<T> *p = currentNode->getLeftNode();
                while (p->getRightNode() != NULL) // todo a la derecha
                {
                    prevP = p;
                    p->getRightNode();
                }
                currentNode->setValue(p->getValue());
                // desconectar el predecesor
                if (p->getLeftNode() != NULL)
                { // tiene un hijo a la izq
                    if (prevP != NULL)
                    {
                        if (p == prevP->getLeftNode())
                            prevP->setLeftNode(currentNode->getLeftNode());
                        else 
                            prevP->setRightNode(currentNode->getLeftNode());
                    }
                }
                else
                { // se trata de un nodo hoja
                    if (p == prevP->getLeftNode())
                        prevP->setLeftNode(NULL);
                    else
                        prevP->setRightNode(NULL);
                }
                delete p;
                return true;
            }
            else
            { // tiene un solo hijo
                if (prevNode != NULL)
                {
                    if (prevNode->getLeftNode() == currentNode)
                    {
                        if (currentNode->getLeftNode() != NULL)
                            prevNode->setLeftNode(currentNode->getLeftNode());
                        else
                            prevNode->setLeftNode(currentNode->getRightNode());
                    }
                    else
                    { // se encuentra a la derecha
                        if (currentNode->getLeftNode() != NULL)
                            prevNode->setRightNode(currentNode->getLeftNode());
                        else
                            prevNode->setRightNode(currentNode->getRightNode());
                    }
                }
                else
                { // se trata del nodo raiz
                    if (currentNode->getLeftNode() != NULL)
                        rootNode = currentNode->getLeftNode();
                    else
                        rootNode = currentNode->getRightNode();
                }
                delete currentNode;
                return true;
            }
        }
        prevNode = currentNode;
        currentNode = (compareNodeValues(value, currentNode->getValue()) == 1 ? currentNode->getRightNode() : currentNode->getLeftNode());
    }
    return false;
}

template <class T>
int BST<T>::count() {
    return count_rec(rootNode);
}

// basado en el recorrido InOrder
template <class T>
int BST<T>::count_rec(TreeNode<T> *node)
{
    if (node == NULL)
        return 0;
    int x=count_rec(node->getLeftNode());
    int y=count_rec(node->getRightNode());
    return (x+y+1);
}

template <class T>
void BST<T>::BFS() {
    markedNodes=new List<T>();
    queue = new Queue<TreeNode<T> *> ();    
    privBFS(rootNode);
  
}

template <class T>
void BST<T>::privBFS(TreeNode<T> *node) {
  markedNodes->add(node->getValue());
  cout<<node->getValue()<<endl;
  queue->enqueue(node);
  while (!queue->isEmpty()) {
  	TreeNode<T> *u=queue->unqueue();
    if ( u->getLeftNode()!=NULL && markedNodes->find(u->getLeftNode()->getValue())!=NULL ) {
        markedNodes->add(node->getLeftNode()->getValue());
        cout<<node->getLeftNode()->getValue()<<endl;
        queue->enqueue(node->getLeftNode());
    }
	if ( u->getRightNode()!=NULL && markedNodes->find(u->getRightNode()->getValue())!=NULL ) {
        markedNodes->add(node->getRightNode()->getValue());
        cout<<node->getRightNode()->getValue()<<endl;
        queue->enqueue(node->getRightNode());
    }
  }
}

