#include <iostream>

class No {
public:
    char dado;
    No* prox;

    No(char value) : dado(value), prox(nullptr) {}
};

class DequeTad {
public:
    No* cabeca;
    No* cauda;

    DequeTad() : cabeca(nullptr), cauda(nullptr) {}

    void inicio() {
        if (cabeca == nullptr) {
            printf("A lista está vazia!\n");
        } else {
            printf("o primeiro elemento é: %c\n", cabeca->dado);
        }
    }

    void fim() {
        if (cauda == nullptr) {
            printf("A lista está vazia!\n");
        } else {
            printf("o último elemento é: %c\n", cauda->dado);
        }
    }

    void insereInicio(char value) {
        No* novoNo = new No(value);

        if (cabeca == nullptr) {
            cabeca = cauda = novoNo;
        } else {
            novoNo->prox = cabeca;
            cabeca = novoNo;
        }
    }

    void insereFim(char value) {
        No* novoNo = new No(value);

        if (cauda == nullptr) {
            cabeca = cauda = novoNo;
        } else {
            cauda->prox = novoNo;
            cauda = novoNo;
        }
    }

    void removeInicio() {
        if (cabeca == nullptr) {
            printf("A lista está vazia. Não é possível remover o primeiro elemento.\n");
        } else {
            No* temp = cabeca;
            cabeca = cabeca->prox;
            delete temp;
        }
    }

    void removeFim() {
        if (cauda == nullptr) {
            printf("A lista está vazia. Não é possível remover o último elemento.\n");
        } else if (cabeca == cauda) {
            delete cauda;
            cabeca = cauda = nullptr;
        } else {
            No* atual = cabeca;
            while (atual->prox != cauda) {
                atual = atual->prox;
            }
            delete cauda;
            cauda = atual;
            cauda->prox = nullptr;
        }
    }
     /*
    Complexidades:
    - inicio() e fim(): Tem complexidade O(1), pois apenas o início e o fim são acessados sem percorrer a lista
    - insereInicio() e insereFim(): Ambas O(1), porque a primeira é colocada no início e é ajustado o ponteiro cabeca para o novo nó, já a outra é inserido no fim e ajusta-se o ponteiro cauda
	- removeInicio(): O(1), pois a remoção é feita no início e basta ajustar o ponteiro cabeca.
	- removeFim(): O(n): n é o número de elementos na lista. No pior caso, quando o último elemento é removido, é necessário percorrer a lista para encontrar o penúltimo nó e atualizar o ponteiro cauda.
    */
};


class PilhaDeque{
public:
    DequeTad d; 

    void push(char dado){
        d.insereFim(dado);
    }
    void pop(){
        d.removeFim();
    }
    void topo(){
        d.fim();
    }
};

class FilaDeque
{
public:
    DequeTad d;

    void enfileira(char dado){
        d.insereFim(dado);
    }

    void desenfileira(){
        d.removeInicio();
    }

    void primeiro(){
        d.inicio();
    }

    void ultimo(){
        d.fim();
    }
};



int main() {
    DequeTad myDeque;

    // 1.a
    myDeque.insereInicio('c');
    myDeque.insereInicio('d');
    myDeque.insereFim('Z');
    myDeque.insereFim('E');

    myDeque.inicio();
    myDeque.fim();
    myDeque.removeFim();
    myDeque.fim();
    // fim 1.a

    printf("\n");

    // 1.b
    PilhaDeque myStack;
    myStack.push('P');
    myStack.push('T');
    myStack.topo();
    // fim 1.b

    printf("\n");

    // 1.3
    FilaDeque myQueue;
    myQueue.enfileira('N');
    myQueue.enfileira('U');
    myQueue.enfileira('W');
    myQueue.desenfileira();
    myQueue.primeiro();
    myQueue.ultimo();
    // fim 1.3

    return 0;
}
