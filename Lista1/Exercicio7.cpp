// pseudo-código pq apanhei para implementar ¯\_(ツ)_/¯  

/*

¯\_(ツ)_/¯


count_vetor = 1;
polones = 0;
topo = 0;

enquanto vetor_index ≤ fim faça
    se expressao[vetor_index] é operando então
        polones = polones + 1
        pol[polones_index] := expressao[vetor_index]
    senão se expressao[vetor_index] é operador então
        topo = topo+1
        pilha[topo] = expressao[vetor_index]
    se não se expressao[vetor_index] = ")" então:
        se topo != 0 então
        operador = pilha[topo]
            topo = topo - 1;
            polones_index = polones_index + 1;
            pol[polones_index] = operador
    se não "expressao errada"
vetor_index = vetor_index + 1

Descrição:
vetor_index -> indice do vetor de expressao
polones_index -> indice polones
fim = tamanho do vetor expressao

*/