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
    if (p->top < (STACKSIZE-1)) 
        p->items[++(p->top)] = elem;
    else
        cout << "Stack overflow";
}

int pop(struct stack *p) {
    if (p->top == -1) {
        cout << "Stack underflow";
        return -1;
    } else 
        return p->items[(p->top)--];
}

int stacktop(struct stack *p) {
    if (empty(p)) {
        cout << "Stack underflow";
        return -1;
    } else 
        return p->items[p->top];
}

bool is_balanced(const string& expression) {
    struct stack s;
    s.top = -1; // Inicializar el tope de la pila
    
    for (char ch : expression) {
        switch (ch) {
            case '(':
                push(&s, ch);
                break;
            case '[':
                push(&s, ch);
                break;
            case '{':
                push(&s, ch);
                break;
            case ')':
                if (empty(&s) || stacktop(&s) != '(') return false;
                pop(&s);
                break;
            case ']':
                if (empty(&s) || stacktop(&s) != '[') return false;
                pop(&s);
                break;
            case '}':
                if (empty(&s) || stacktop(&s) != '{') return false;
                pop(&s);
                break;
        }
    }
    
    return empty(&s);
}

int main() {
    string expression;
    
    while (true) {
        cout << "Introduce una expresión matemática (deja en blanco para salir): ";
        getline(cin, expression);
        
        if (expression.empty()) {
            break;
        }
        
        if (is_balanced(expression)) {
            cout << "La expresión está bien balanceada." << endl;
        } else {
            cout << "La expresión no está balanceada." << endl;
        }
    }

    return 0;
}
