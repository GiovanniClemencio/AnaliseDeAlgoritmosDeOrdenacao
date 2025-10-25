#include <stdio.h>
#include <stdlib.h>

void Merge(int *vetor, int inicio, int meio, int fim){
    int i = inicio,
        j = meio + 1,
        k = 0;

    int tamanho = fim - inicio + 1;
    int *aux = (int*) malloc(tamanho * sizeof(int));

    while(i <= meio && j <= fim){
        if(vetor[i] <= vetor[j]){
            aux[k] = vetor[i];
            i++;
        }else{
            aux[k] = vetor[j];
            j++;
        }
        k++;
    }

    while(i <= meio){
        aux[k] = vetor[i];
        i++;
        k++;
    }

    while(j <= fim){
        aux[k] = vetor[j];
        j++;
        k++;
    }

    for(i = inicio, k=0; i <=fim; i++, k++){
        vetor[i] = aux[k];
    }

    free(aux);
}

void MergeSort(int *vetor, int inicio, int fim){
    int meio;

    if(inicio < fim){
        meio = floor((inicio + fim)/2);
        MergeSort(vetor, inicio, meio);
        MergeSort(vetor, meio + 1, fim);
        Merge(vetor, inicio, meio, fim);
    }
}
