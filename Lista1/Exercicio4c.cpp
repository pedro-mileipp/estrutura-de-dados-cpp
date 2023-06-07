#include <stack>
#include <iostream>

void inverte(std::stack<char> *p) {
    std::stack<char> p1;

    // transferindo os elementos da pilha parâmetro para a pilha p1
    while(p->size()){
        p1.push(p->top());
        p->pop();
    }
    
    // ao transferir os elementos naturalmente eles estarão invertidos, basta atribuir p1 em p
    *p = p1;
}

/**
 
A complexidade de inverte é O(n) pois irá ser necessário percorrer a pilha toda.

*/

int main() {
    std::stack<char> p;
    p.push('P');
    p.push('E');
    p.push('D');
    p.push('R');
    p.push('O');



    inverte(&p);
    printf("Conteúdo da pilha invertido: ");
    while (!p.empty()) {
        printf("%c ", p.top());
        p.pop();
    }
    printf("\n");

    return 0;
}
