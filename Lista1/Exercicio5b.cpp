#include <queue>
#include <cstdio>

void inverte(std::queue<char> *f){
    std::queue<char> f1;
    std::queue<char> f2;
    while(true){ // loop infinito
        int tamanhoF = f->size(); // tamanho da fila f
        
        if (tamanhoF != 0) {
            for (int i = 0; i < tamanhoF - 1; i++) { // percorrerá até o penúltimo || f = 2 (1° volta)
                f1.push(f->front()); // adiciona em f1 os elementos de f
                f->pop(); // tira de f
            }
            f2.push(f->front()); // adiciona o último elemento de f em f2
            f->pop(); // esvazia f
        }else{
            break;
        }
        
        int tamanhoF1 = f1.size(); // recebe o tamanho de f1
        if (tamanhoF1 != 0) { // verifica se a fila está vazia
            for (int i = 0; i < tamanhoF1 - 1; i++) {
                f->push(f1.front());
                f1.pop();
            }
            f2.push(f1.front());
            f1.pop();
        } else { // se estiver vazia, f recebe f2 (fila invertida) e quebra o laço
            *f = f2;
            break;
        }
    }
}


/*
 COMPLEXIDADE:
 É O(n²) sendo n o número de elementos da fila. Isso ocorre devido aos dois loops aninhados que percorrem os elementos da fila passada como parâmetro
*/
int main() {
    std::queue<char> f;
    f.push('X');
    f.push('Y');
    f.push('Z');

    inverte(&f);

    printf("Conteúdo da fila invertido: ");
    while (!f.empty()) {
        printf("%c ", f.front());
        f.pop();
    }
    printf("\n");

    return 0;
}

/*
A ideia do algoritmo é deixar um elemento em cada fila para depois inserir eles na fila2(f2) e depois a atribuir a f.
*/


/*
TESTE DE MESA
1° VOLTA WHILE
	PRIMEIRO IF
	  DADOS DE ENTRADA:
	   F -> X Y Z
	   F1 -> VAZIO
	   F2 -> VAZIO
           
           FOR (1° VOLTA)
	     F1 -> X
             F -> Y Z
	   FOR (2° VOLTA)
	     F1 -> X Y *
	     F -> Z
	F2 -> Z *
	F -> VAZIO *

	SEGUNDO IF
	  DADOS DE ENTRADA:
	    F -> VAZIO
	    F1 -> X Y
	    F2 -> Z
	FOR (1° VOLTA)
	  F -> X
	  F1 -> Y
	F2 -> Z 
	F1 -> VAZIO

2° VOLTA DO WHILE  	
	PRIMEIRO IF
	  DADOS DE ENTRADA:
	    F -> X 
	    F1 -> VAZIO
	    F2 -> Z Y
	  F2 -> Z Y X
	  F -> VAZIO
*/