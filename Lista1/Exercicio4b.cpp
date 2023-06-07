#include <stack>
#include <iostream>

void inverte(std::stack<char>* p) {
    std::stack<char> p1; 
    std::stack<char> p2; 

    // Original para primeira auxiliar
    while (!p->empty()) {
        p1.push(p->top());
        p->pop();
    }

    // Primeira auxiliar para segunda auxiliar
    while (!p1.empty()) {
        p2.push(p1.top());
        p1.pop();
    }

    // tranferindo de volta para a original
    while (!p2.empty()) {
        p->push(p2.top());
        p2.pop();
    }
}

/*
Complexidade

O(n), pois os dois loops vão executar de acordo com o valor de n, que corresponde a quantidade de elementos da pilha
*/


int main() {
    std::stack<char> p;
    p.push('A');
    p.push('B');
    p.push('C');

    inverte(&p);

    printf("Pilha invertida: ");
    while (!p.empty()) {
        printf("%c ", p.top());
        p.pop();
    }
    printf("\n");

    return 0;
}
