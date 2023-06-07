#include <stack>
#include <iostream>

class Fila2P {
public:
    std::stack<char> p1; // Pilha para 'char'
    std::stack<char> p2; // Pilha para 'char'

    // Função que retorna true se a fila estiver vazia, false caso contrário
    bool estaVazia() {
        return p1.empty() && p2.empty();
    }

    // Função que insere um elemento no final da fila
    void enfileira(char value) {
        // Transferir todos os elementos de p1 para p2
        while (!p1.empty()) {
            p2.push(p1.top());
            p1.pop();
        }

        // Inserir o novo elemento em p1
        p1.push(value);

        // Transferir todos os elementos de p2 de volta para p1
        while (!p2.empty()) {
            p1.push(p2.top());
            p2.pop();
        }
    }

    // Função que remove o elemento do início da fila e retorna seu valor
    char desenfileira() {
        if (estaVazia()) {
            printf("Fila vazia!\n");
            return '\0'; // Retorna um valor nulo se a fila estiver vazia
        }

        char value = p1.top();
        p1.pop();
        return value;
    }

    // Função que retorna o valor do elemento do início da fila
    char inicio() {
        if (estaVazia()) {
            printf("Fila vazia!\n");
            return '\0'; // Retorna um valor nulo se a fila estiver vazia
        }

        return p1.top();
    }
};



/*
 Complexidades:
 - vazia(): O(1), a função apenas verifica se as duas pilhas estão vazias.
 - enfileira(): O(n): No pior dos casos, quando for inserido um novo elemento, os demais terão de ser transferidos para a outra pilha.
 - desenfileira(): O(1): a função só remove o início da pilha p1.
 - inicio(): O(1): pois apenas retorna o valor do elemento do início da pilha p1
*/


int main() {
    Fila2P minhaFila;

    minhaFila.enfileira('A');
    minhaFila.enfileira('B');
    minhaFila.enfileira('C');

    

    // Removendo elementos da fila:
    while (!minhaFila.estaVazia()) {
        printf("%c \n", minhaFila.desenfileira());
    }
    

    return 0;
}
