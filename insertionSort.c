void insertionSort(int *vetor, int n){
    int k, i;
    for(k = 1; k < n; k++){
        int y = vetor[k];
        for(i = k-1; i >= 0 && vetor[i] > y; i--)
            vetor[i+1] = vetor[i];
        vetor[i+1] = y;
    }
}

