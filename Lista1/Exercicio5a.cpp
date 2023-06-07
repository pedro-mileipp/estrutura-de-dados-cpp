#include <queue>
#include <stack>
#include <iostream>

void inverte(std::queue<char>* f) {
    std::stack<char> p; // Pilha auxiliar

    // Transferir os elementos da fila para a pilha
    while (!f->empty()) {
        p.push(f->front());
        f->pop();
    }

    // Transferir os elementos da pilha de volta para a fila (inverter a ordem)
    while (!p.empty()) {
        f->push(p.top());
        p.pop();
    }
}


/**
 Complexidade é O(n), sendo N o número de elementos da fila que são movidos duas vezes.
*/

int main()
{
    std::queue<char> myFila;
    myFila.push('A'); myFila.push('B'); myFila.push('C');

    inverte(&myFila);

    while (!myFila.empty())
    {
        printf("%c ", myFila.front());
        myFila.pop();
    }

    printf("\n");
    
    return 0;
}
