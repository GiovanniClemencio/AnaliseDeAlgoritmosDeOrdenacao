int* BubbleSortClassico(int *vetor, int tamanho){
    for(int i = 0 ; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(vetor[j] > vetor[j + 1]){
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

    return vetor;
}

int* BubbleSortMelhorado(int *vetor, int tamanho){
    int troca = 1;
    for(int i = 0 ; i < tamanho; i++){
        troca = 0;
        for(int j = 0; j < tamanho; j++){
            if(vetor[j] > vetor[j + 1]){
                troca = 1;
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
        if(!troca) return vetor;
    }

    return vetor;
}
