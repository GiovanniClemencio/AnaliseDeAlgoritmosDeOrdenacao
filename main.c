#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include<string.h>
#include "Bubble.c"
#include "QuickSort.c"
#include "InsertionSort.c"
#include "ShellSort.c"
#include "selectionSort.c"
#include "HeapSort.c"
#include "MergeSort.c"

// Função para carregar vetor de arquivo
void carregarVetor(const char *nomeArquivo, int *vetor, int n) {
    FILE *f = fopen(nomeArquivo, "r");
    if (!f) {
        printf("Erro ao abrir %s\n", nomeArquivo);
        exit(1);
    }

    for (int i = 0; i < n; i++)
        fscanf(f, "%d", &vetor[i]);

    fclose(f);
}

// Geração de casos derivados
void gerarCrescente(int *vetor, int n) {
    for (int i = 0; i < n; i++)
        vetor[i] = i;
}

void gerarDecrescente(int *vetor, int n) {
    for (int i = 0; i < n; i++)
        vetor[i] = n - i;
}

// Função para medir tempo médio de execução de um algoritmo
double medir_tempo_medio(void (*func)(int*, int), int *vetor, int n, const char *tipo, const char *alg, const char *nomeArquivo, int repeticoes) {
    struct timespec inicio, fim;
    double soma = 0.0;

    for (int r = 0; r < repeticoes; r++) {
        if (strcmp(tipo, "Aleatorio") == 0)
            carregarVetor(nomeArquivo, vetor, n);
        else if (strcmp(tipo, "Crescente") == 0)
            gerarCrescente(vetor, n);
        else
            gerarDecrescente(vetor, n);

        clock_gettime(CLOCK_MONOTONIC, &inicio);
        func(vetor, n);
        clock_gettime(CLOCK_MONOTONIC, &fim);

        double tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
        soma += tempo;
    }

    return soma / repeticoes;
}

double medir_tempo_medio_merge(void (*func)(int*, int, int), int *vetor, int n, const char *tipo, const char *nomeArquivo, int repeticoes) {
    struct timespec inicio, fim;
    double soma = 0.0;

    for (int r = 0; r < repeticoes; r++) {
        if (strcmp(tipo, "Aleatorio") == 0)
            carregarVetor(nomeArquivo, vetor, n);
        else if (strcmp(tipo, "Crescente") == 0)
            gerarCrescente(vetor, n);
        else
            gerarDecrescente(vetor, n);

        clock_gettime(CLOCK_MONOTONIC, &inicio);
        func(vetor, 0, n);
        clock_gettime(CLOCK_MONOTONIC, &fim);

        double tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
        soma += tempo;
    }

    return soma / repeticoes;
}

int main() {
    FILE *arquivo = fopen("tempos_ordenacao.csv", "w");
    if (!arquivo) {
        printf("Erro ao criar arquivo de saída!\n");
        return 1;
    }

    fprintf(arquivo, "Tamanho,Algoritmo,Tipo_Entrada,Tempo_Medio(s)\n");

    int tamanhos[] = {1000, 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 100000, 150000, 200000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    int repeticoes = 10; // número de repetições para calcular a média

    for (int t = 0; t < num_tamanhos; t++) {
        int n = tamanhos[t];
        int *vetor = malloc(n * sizeof(int));
        if (!vetor) {
            printf("Erro de alocação!\n");
            return 1;
        }

        char nomeArquivo[50];
        sprintf(nomeArquivo, "vetor_%d.txt", n);

        fprintf(arquivo, "%d,BubbleSortClassico,Aleatorio,%.9f\n", n, medir_tempo_medio(BubbleSortClassico, vetor, n, "Aleatorio", "BubbleSortClassico", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,BubbleSortClassico,Crescente,%.9f\n", n, medir_tempo_medio(BubbleSortClassico, vetor, n, "Crescente", "BubbleSortClassico", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,BubbleSortClassico,Decrescente,%.9f\n", n, medir_tempo_medio(BubbleSortClassico, vetor, n, "Decrescente", "BubbleSortClassico", nomeArquivo, repeticoes));

        fprintf(arquivo, "%d,BubbleSortMelhorado,Aleatorio,%.9f\n", n, medir_tempo_medio(BubbleSortMelhorado, vetor, n, "Aleatorio", "BubbleSortMelhorado", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,BubbleSortMelhorado,Crescente,%.9f\n", n, medir_tempo_medio(BubbleSortMelhorado, vetor, n, "Crescente", "BubbleSortMelhorado", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,BubbleSortMelhorado,Decrescente,%.9f\n", n, medir_tempo_medio(BubbleSortMelhorado, vetor, n, "Decrescente", "BubbleSortMelhorado", nomeArquivo, repeticoes));

        fprintf(arquivo, "%d,QuickSortInicio,Aleatorio,%.9f\n", n, medir_tempo_medio(quickSortInicio, vetor, n, "Aleatorio", "QuickSortInicio", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,QuickSortInicio,Crescente,%.9f\n", n, medir_tempo_medio(quickSortInicio, vetor, n, "Crescente", "QuickSortInicio", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,QuickSortInicio,Decrescente,%.9f\n", n, medir_tempo_medio(quickSortInicio, vetor, n, "Decrescente", "QuickSortInicio", nomeArquivo, repeticoes));

        fprintf(arquivo, "%d,QuickSortMeio,Aleatorio,%.9f\n", n, medir_tempo_medio(quickSortMeio, vetor, n, "Aleatorio", "QuickSortMeio", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,QuickSortMeio,Crescente,%.9f\n", n, medir_tempo_medio(quickSortMeio, vetor, n, "Crescente", "QuickSortMeio", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,QuickSortMeio,Decrescente,%.9f\n", n, medir_tempo_medio(quickSortMeio, vetor, n, "Decrescente", "QuickSortMeio", nomeArquivo, repeticoes));

        fprintf(arquivo, "%d,InsertionSort,Aleatorio,%.9f\n", n, medir_tempo_medio(insertionSort, vetor, n, "Aleatorio", "InsertionSort", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,InsertionSort,Crescente,%.9f\n", n, medir_tempo_medio(insertionSort, vetor, n, "Crescente", "InsertionSort", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,InsertionSort,Decrescente,%.9f\n", n, medir_tempo_medio(insertionSort, vetor, n, "Decrescente", "InsertionSort", nomeArquivo, repeticoes));

        fprintf(arquivo, "%d,ShellSort,Aleatorio,%.9f\n", n, medir_tempo_medio(shellSort, vetor, n, "Aleatorio", "ShellSort", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,ShellSort,Crescente,%.9f\n", n, medir_tempo_medio(shellSort, vetor, n, "Crescente", "ShellSort", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,ShellSort,Decrescente,%.9f\n", n, medir_tempo_medio(shellSort, vetor, n, "Decrescente", "ShellSort", nomeArquivo, repeticoes));

        fprintf(arquivo, "%d,SelectionSort,Aleatorio,%.9f\n", n, medir_tempo_medio(selectionSort, vetor, n, "Aleatorio", "SelectionSort", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,SelectionSort,Crescente,%.9f\n", n, medir_tempo_medio(selectionSort, vetor, n, "Crescente", "SelectionSort", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,SelectionSort,Decrescente,%.9f\n", n, medir_tempo_medio(selectionSort, vetor, n, "Decrescente", "SelectionSort", nomeArquivo, repeticoes));

        fprintf(arquivo, "%d,HeapSort,Aleatorio,%.9f\n", n, medir_tempo_medio(heapSort, vetor, n, "Aleatorio", "HeapSort", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,HeapSort,Crescente,%.9f\n", n, medir_tempo_medio(heapSort, vetor, n, "Crescente", "HeapSort", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,HeapSort,Decrescente,%.9f\n", n, medir_tempo_medio(heapSort, vetor, n, "Decrescente", "HeapSort", nomeArquivo, repeticoes));

        fprintf(arquivo, "%d,MergeSort,Aleatorio,%.9f\n", n, medir_tempo_medio_merge(MergeSort, vetor, n, "Aleatorio", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,MergeSort,Crescente,%.9f\n", n, medir_tempo_medio_merge(MergeSort, vetor, n, "Crescente", nomeArquivo, repeticoes));
        fprintf(arquivo, "%d,MergeSort,Decrescente,%.9f\n", n, medir_tempo_medio_merge(MergeSort, vetor, n, "Decrescente", nomeArquivo, repeticoes));

        free(vetor);
    }

    fclose(arquivo);
    printf("Execucao concluida! Resultados salvos em tempos_ordenacao.csv\n");
    return 0;
}
