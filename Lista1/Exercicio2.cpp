#include <queue>
#include <iostream>

class Pilha2F {
public:
    std::queue<char> f1; // Fila para 'char'
    std::queue<char> f2; // Fila para 'char'

    // Função que retorna true se a pilha estiver vazia, false caso contrário
    bool estaVazia() {
        return f1.empty() && f2.empty();
    }

    // Função que insere um elemento no topo da pilha
    void Push(char dado) {
        // Inserir o elemento na fila não vazia
        if (!f1.empty()) {
            f1.push(dado);
        } else {
            f2.push(dado);
        }
    }

    // Função que remove o elemento do topo da pilha e retorna seu valor
    char Pop() {
        if (estaVazia()) {
            printf("Pilha vazia!.\n" );
            return '\0'; // Retorna um valor nulo se a pilha estiver vazia
        }

        char dado;

        // Remover o elemento da fila não vazia
        if (!f1.empty()) {
            // Transfere os elementos de f1 para f2, exceto o último elemento
            while (f1.size() > 1) {
                f2.push(f1.front());
                f1.pop();
            }

            // Obter o valor do último elemento em f1
            dado = f1.front();
            f1.pop();
        } else {
            // Transfere os elementos de f2 para f1, exceto o último elemento
            while (f2.size() > 1) {
                f1.push(f2.front());
                f2.pop();
            }

            // Obter o valor do último elemento em f2
            dado = f2.front();
            f2.pop();
        }

        return dado;
    }

    // Função que retorna o valor do elemento do topo da pilha
    char top() {
        if (estaVazia()) {
            printf("Pilha vazia!\n" );
            return '\0'; // Retorna um valor nulo se a pilha estiver vazia
        }

        char dado;

        // Obter o valor do elemento do topo da fila não vazia
        if (!f1.empty()) {
            dado = f1.back();
        } else {
            dado = f2.back();
        }

        return dado;
    }
};


/*

Complexidades
- vazia(): O(1), só verifica se as filas estão vazias;
- push(): O(1), inserção feita em tempo em uma das filas não vazias
- pop(): O(n). No pior caso, se o último elemento for ser removido, é necessário transferir todos os elementos de uma fila para outra, execeto o último.
- top(): O(1), retorna apenas o valor do elemento no topo da pilha.


*/

int main() {
    Pilha2F minhaPilha;

    minhaPilha.Push('A');
    minhaPilha.Push('B');
    minhaPilha.Push('C');
    

    // Removendo elementos da pilha, esvaziando a pilha
    // while (!minhaPilha.vazia()) {
    //     printf("%c\n", minhaPilha.pop());
    // }
    

    return 0;
}

