int* shellSort(int *vetor, int tamanho){
    int salto, menor, k;
    int incrementos[64], indiceIncrementos = 1;

    incrementos[0] = 1;
    while(indiceIncrementos < tamanho){
        incrementos[indiceIncrementos] = 2 * incrementos[indiceIncrementos - 1] - 1; // 2^k - 1
        indiceIncrementos++;
    }
    indiceIncrementos--; // Agora est� na �ltima posi��o de incrementos (ou seja no primeiro incremento)

    for(int i = indiceIncrementos; i >=0; i--){ // esse la�o � para ir diminuindo os incrementos
        salto = incrementos[i];
        for(int j = salto; j < tamanho; j++){ // esse la�o � o que seleciona
            menor = vetor[j];
            for(k = j - salto; k >= 0 && vetor[k] > menor; k-= salto){
                vetor[k + salto] = vetor[k];
            }
            vetor[k + salto] = menor;
        }
    }
    return vetor;
}

