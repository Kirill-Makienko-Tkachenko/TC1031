#include <iostream>

using namespace std;

enum SplayCase
{
    scTreeEmpty = 1,
    scInNode = 2,
    scNoChild = 3,
    scZigLeft = 4,
    scZigRight = 5,
    scZigZigLeft = 6,
    scZigZigRight = 7,
    scZigZagLeft = 8,
    scZigZagRight = 9
};

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
class SplayTree
{
private:
    TreeNode<T> *rootNode;

public:
    SplayTree<T>() { rootNode = NULL; }
    bool addValue(T *value);

    bool removeValue(T *value);
    int compareNodeValues(T *v1, T *v2);
    void display();
    void InOrder(TreeNode<T> *node);
    void PreOrder(TreeNode<T> *node);
    // nuevos
    int count();
    int count_rec(TreeNode<T> *node);

    SplayCase GetSplayCase(TreeNode<T> *node, T *value);
    TreeNode<T> *Splay(TreeNode<T> *node, T *value);
    TreeNode<T> *TurnRight(TreeNode<T> *node);
    TreeNode<T> *TurnLeft(TreeNode<T> *node);
    bool findValue(T *value);
};

template <class T>
int SplayTree<T>::compareNodeValues(T *v1, T *v2)
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
bool SplayTree<T>::addValue(T *value)
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

    rootNode = Splay(rootNode, value);
    return true;
}

template <class T>
bool SplayTree<T>::findValue(T *value)
{
    /*
    TreeNode<T> *newNode, *currentNode = rootNode;
    while (currentNode != NULL)
    {
        if (compareNodeValues(value, currentNode->getValue()) == 0)
            return true;
        currentNode = (compareNodeValues(value, currentNode) == 1 ? currentNode->getRightNode() : currentNode->getLeftNode());
    }
    return false;
    */
    rootNode = Splay(rootNode, value);
    return (compareNodeValues(rootNode->getValue(), value) == 0);
}

template <class T>
void SplayTree<T>::display()
{
    PreOrder(rootNode);
}

template <class T>
void SplayTree<T>::PreOrder(TreeNode<T> *node)
{
    if (node == NULL)
        return;
    cout << *(node->getValue()) << " ";
    PreOrder(node->getLeftNode());
    PreOrder(node->getRightNode());
}


template <class T>
void SplayTree<T>::InOrder(TreeNode<T> *node)
{
    if (node == NULL)
        return;
    InOrder(node->getLeftNode());
    cout << *(node->getValue()) << " ";
    InOrder(node->getRightNode());
}

template <class T>
bool SplayTree<T>::removeValue(T *value)
{
    TreeNode<T> *newNode, *prevNode = NULL, *currentNode = rootNode;
    while (currentNode != NULL)
    {
        if (compareNodeValues(value, currentNode->getValue()) == 0)
        { // ya lo encontramos
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
                cout << "Nodo con dos hijos" << endl;
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
int SplayTree<T>::count()
{
    return count_rec(rootNode);
}

// basado en el recorrido InOrder
template <class T>
int SplayTree<T>::count_rec(TreeNode<T> *node)
{
    if (node == NULL)
        return 0;
    int x = count_rec(node->getLeftNode());
    int y = count_rec(node->getRightNode());
    return (x + y + 1);
}

template <class T>
SplayCase SplayTree<T>::GetSplayCase(TreeNode<T> *node, T *value)
{
    if (node == NULL)
        return scTreeEmpty;
    else if (compareNodeValues(node->getValue(), value) == 0)
        return scInNode;
    else if (compareNodeValues(value, node->getValue()) < 0)
    {
        TreeNode<T> *childNode = node->getLeftNode();
        if (childNode == NULL)
            return scNoChild;
        else if (compareNodeValues(value, childNode->getValue()) == 0)
            return scZigLeft;
        else
        {
            if (compareNodeValues(value, childNode->getValue()) < 0)
                return scZigZigLeft;
            else
                return scZigZagLeft;
        }
    }
    else
    { // value > node->getValue()
        TreeNode<T> *childNode = node->getRightNode();
        if (childNode == NULL)
            return scNoChild;
        else if (compareNodeValues(value, childNode->getValue()) == 0)
            return scZigRight;
        else
        { // if (compareNodeValues(value,childNode->getValue())>0)
            if (*value > *(childNode->getValue()))
                return scZigZigRight; 
            else 
                return scZigZagRight;
        }
    }
}


template <class T>
TreeNode<T> *SplayTree<T>::TurnRight(TreeNode<T> *node)
{
    TreeNode<T> *childNode = node->getLeftNode();
    TreeNode<T> *childChildNode = childNode->getRightNode();
    node->setLeftNode(childChildNode);
    childNode->setRightNode(node);
    return childNode;
}

template <class T>
TreeNode<T> *SplayTree<T>::TurnLeft(TreeNode<T> *node)
{
    TreeNode<T> *childNode = node->getRightNode();
    TreeNode<T> *childChildNode = childNode->getLeftNode();
    node->setRightNode(childChildNode);
    childNode->setLeftNode(node);
    return childNode;
}

template <class T>
TreeNode<T> *SplayTree<T>::Splay(TreeNode<T> *node, T *value)
{
    SplayCase sc = GetSplayCase(node, value);
    switch (sc)
    {
    case scTreeEmpty:
    case scInNode:
    case scNoChild:
        return node;
    case scZigLeft:
        return TurnRight(node);
    case scZigRight:
        return TurnLeft(node);
    case scZigZigLeft:
        node->getLeftNode()->setLeftNode(Splay(node->getLeftNode()->getLeftNode(), value));
        node = TurnRight(node);
        return TurnRight(node);
    case scZigZigRight:
        node->getRightNode()->setRightNode(Splay(node->getRightNode()->getRightNode(), value));
        node = TurnLeft(node);
        return TurnLeft(node);
    case scZigZagLeft:
        node->getLeftNode()->setRightNode(Splay(node->getLeftNode()->getRightNode(), value));
        node->setLeftNode(TurnLeft(node->getLeftNode()));
        return TurnRight(node);
    case scZigZagRight:
        node->getRightNode()->setLeftNode(Splay(node->getRightNode()->getLeftNode(), value));
        node->setRightNode(TurnRight(node->getRightNode()));
        return TurnLeft(node);
    }
}