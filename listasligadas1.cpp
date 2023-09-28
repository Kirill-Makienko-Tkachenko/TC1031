#include <iostream>

using namespace std;

class Nodo
{
public:
  Nodo(int valor)
  {
    this->info = valor;
    sig = NULL;
  }
  Nodo() { sig = NULL; }
  int info;
  Nodo *sig = NULL;
};

class List
{
public:
  List() { inicio = NULL; };
  void add(int valor);
  bool remove(int valor);
  bool esta_vacia();
  Nodo *GetLast();
  Nodo *GetFirst() { return inicio; }
  void desplegarLista();

private:
  Nodo *inicio;
};

void List::add(int valor)
{
  Nodo *nodo = new Nodo(valor);
  if (inicio == NULL)
  {
    inicio = nodo;
  }
  else
  {
    Nodo *ultimo = GetLast();
    ultimo->sig = nodo;
  }
}

bool List::esta_vacia()
{
  return inicio == NULL;
}

Nodo *List::GetLast()
{
  if (esta_vacia())
    return NULL;

  Nodo *p = inicio;
  while (p->sig != NULL)
  {
    p = p->sig;
  }
  return p;
}

void List::desplegarLista()
{
  Nodo *p = inicio;
  while (p != NULL)
  {
    cout << p->info << "\n";
    p = p->sig;
  }
}

bool List::remove(int valor)
{
  Nodo *nodo = GetFirst();
  Nodo *nodoAnt = NULL;
  bool encontro = false;
  while (nodo != NULL)
  {
    if (nodo->info == valor)
    {
      if (nodoAnt != NULL)
      { // hay un nodo antes
        nodoAnt->sig = nodo->sig;
      }
      else                  // no hay un nodo antes
        inicio = nodo->sig; // el nodo que sigue pasa a ser el inicio
      delete nodo;
      return true;
    }
    nodoAnt = nodo;
    nodo = nodo->sig;
  }
  return encontro;
}

int main()
{
  int numero;
  List *lista = new List();
  do
  {
    cout << " Dame un numero (0 para terminar):";
    cin >> numero;
    lista->add(numero);
  } while (numero != 0);
  lista->desplegarLista();
  getchar();
}
