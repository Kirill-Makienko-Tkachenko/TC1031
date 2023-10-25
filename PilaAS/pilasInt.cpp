#include <iostream>
using namespace std;

#define STACKSIZE 100
struct stack {
		int top;    // indica el índice del tope
		int items[STACKSIZE];
};

bool empty(struct stack *p){
	return (p->top==-1);
}

void push(struct stack *p, int elem) {
	if (p->top<(STACKSIZE-1)) 
  	p->items[++(p->top)]=elem;
  else
  	cout<<"Stack overflow";
}

int pop(struct stack *p) {
	if (p->top==-1) {
  	cout<<"Stack underflow";
    return -1;
  } else 
  	return p->items[(p->top)--];
}

int stacktop(struct stack *p) {
	if (empty(p)) {
  	cout<<"Stack underflow";
    return -1;
  } else 
  	return p->items[p->top];
}


int main() {
	struct stack pila;
	pila.top=-1;
  
  int valor=-1;
  do {
  	cout<<"Dame un valor para la pila, 0 para terminar:";
    cin>>valor;
    if (valor>0)
    	 push(&pila,valor);
  } while (valor!=0);
  cout<<"Volcado de la pila:" << endl;
  
  while (!empty(&pila))
  	cout<<pop(&pila)<<endl;
  
}






