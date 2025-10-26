int* shellSort(int *vetor, int tamanho){
    int salto, temp, k;
    int incrementos[64], indiceIncrementos = 0; // Inicia em 0

    // gera��o dos Incrementos (Sequ�ncia 1, 3, 7, 15, ...)
    salto = 1;
    while(salto < tamanho){
        incrementos[indiceIncrementos++] = salto;
        salto = 2 * salto + 1;
    }
    for(int i = indiceIncrementos - 1; i >= 0; i--){ // la�o para ir diminuindo os incrementos
        salto = incrementos[i];

        for(int j = salto; j < tamanho; j++){
            temp = vetor[j]; // valor a ser inserido

            // k come�a na posi��o anterior que tem salto de dist�ncia
            for(k = j - salto; k >= 0 && vetor[k] > temp; k-= salto){
                vetor[k + salto] = vetor[k]; // desloca o elemento
            }
            vetor[k + salto] = temp; // insere o valor na posi��o correta
        }
    }
    return vetor;
}

