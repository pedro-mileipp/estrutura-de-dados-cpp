#include <iostream>


constexpr int MAXN = 100'000;
class Pilha{
public:
    int elementos[MAXN];
    int N;

    void cria(){
        this->N = 0;
    };

    //Complexidade: O(1)
    int topo(){
        return this->elementos[N-1];
    };
    
    void empilha(int dado){
        //Complexidade: O(1)
        this->elementos[N] = dado;
        this->N++;
    };

    int desempilha(){
        //Complexidade: O(1)
        this->N--;
        return elementos[N];
    }
    int obterMin(){
        int menor = INT64_MAX;
        int cont = N-1;
        
        //Complexidade: O(n)
        while(cont > 0){
        //Complexidade: O(1)
            if(elementos[cont] < menor){
                menor = elementos[cont];
        }
            //Complexidade: O(1)
            cont--;
        }
        return menor;
    }
};

/*

Todos exceto obterMin terão complexidade O(1), pois trabalham com extremidades.
obterMin() tem complexidade O(n) sendo n o número de elementos da lista, pois para achar o menor é necessário percorrer a lista toda.

*/
