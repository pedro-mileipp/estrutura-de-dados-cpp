#include <iostream>
#include <stack>
#include <queue>

void inverte(std::stack<char>* p) {
    std::queue<char> f; // Fila para armazenar os elementos temporariamente

    // Passando os elementos da pilha para a fila
    while (!p->empty()) {
        f.push(p->top());
        p->pop();
    }

    // Passando de volta para pilha
    while (!f.empty()) {
        p->push(f.front());
        f.pop();
    }
}



/*
Complexidade

A complexidade é O(n), para transferir os elementos da pilha para fila e depois da fila para pilha requer um loop que vai ocorrer n vezes, sendo n a quantidade de elementos
*/

int main() {
    std::stack<char> pilha;

    // Preenchendo a pilha com caracteres
    pilha.push('x');
    pilha.push('y');
    pilha.push('z');
    pilha.push('w');
    // D C B A

    printf("\n");
    
    // Inverter a pilha
    inverte(&pilha);

    printf("Pilha depois da inversao: ");
    while (!pilha.empty()) {
        printf("%c ", pilha.top());
        pilha.pop();
    }
    

    return 0;
}
