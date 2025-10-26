#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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

int main() {
    FILE *arquivo = fopen("tempos_ordenacao.csv", "w");
    if (!arquivo) {
        printf("Erro ao criar arquivo de saída!\n");
        return 1;
    }

    fprintf(arquivo, "Tamanho,Algoritmo,Tipo_Entrada,Tempo(s)\n");

    int tamanhos[] = {1000, 5000, 10000, 15000, 20000, 25000, 30000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int t = 0; t < num_tamanhos; t++) {
        int n = tamanhos[t];
        int *vetor = malloc(n * sizeof(int));
        if (!vetor) {
            printf("Erro de alocação!\n");
            return 1;
        }

        char nomeArquivo[50];
        sprintf(nomeArquivo, "vetor_%d.txt", n);

        // BubbleSortClassico
        // -------- aleatório do arquivo --------
        carregarVetor(nomeArquivo, vetor, n);
        clock_t inicio = clock();
        BubbleSortClassico(vetor, n);
        clock_t fim = clock();
        fprintf(arquivo, "%d,BubbleSortClassico,Aleatorio,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- crescente --------
        gerarCrescente(vetor, n);
        inicio = clock();
        BubbleSortClassico(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,BubbleSortClassico,Crescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- decrescente --------
        gerarDecrescente(vetor, n);
        inicio = clock();
        BubbleSortClassico(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,BubbleSortClassico,Decrescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);


        // BubbleSortMelhorado
        // -------- aleatório do arquivo --------
        carregarVetor(nomeArquivo, vetor, n);
        inicio = clock();
        BubbleSortMelhorado(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,BubbleSortMelhorado,Aleatorio,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- crescente --------
        gerarCrescente(vetor, n);
        inicio = clock();
        BubbleSortMelhorado(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,BubbleSortMelhorado,Crescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- decrescente --------
        gerarDecrescente(vetor, n);
        inicio = clock();
        BubbleSortMelhorado(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,BubbleSortMelhorado,Decrescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // Quick Sort (com pivô no início)
        // -------- aleatório do arquivo --------
        carregarVetor(nomeArquivo, vetor, n);
        inicio = clock();
        quickSortInicio(vetor, 0, n -1);
        fim = clock();
        fprintf(arquivo, "%d,QuickSortInicio,Aleatorio,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- crescente --------
        gerarCrescente(vetor, n);
        inicio = clock();
        quickSortInicio(vetor, 0, n -1);
        fim = clock();
        fprintf(arquivo, "%d,QuickSortInicio,Crescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- decrescente --------
        gerarDecrescente(vetor, n);
        inicio = clock();
        quickSortInicio(vetor, 0, n -1);
        fim = clock();
        fprintf(arquivo, "%d,QuickSortInicio,Decrescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // Quick Sort (com pivô no meio)
        // -------- aleatório do arquivo --------
        carregarVetor(nomeArquivo, vetor, n);
        inicio = clock();
        quickSortMeio(vetor, 0, n -1);
        fim = clock();
        fprintf(arquivo, "%d,QuickSortMeio,Aleatorio,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- crescente --------
        gerarCrescente(vetor, n);
        inicio = clock();
        quickSortMeio(vetor, 0, n -1);
        fim = clock();
        fprintf(arquivo, "%d,QuickSortMeio,Crescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- decrescente --------
        gerarDecrescente(vetor, n);
        inicio = clock();
        quickSortMeio(vetor, 0, n -1);
        fim = clock();
        fprintf(arquivo, "%d,QuickSortMeio,Decrescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // Insertion Sort
        // -------- aleatório do arquivo --------
        carregarVetor(nomeArquivo, vetor, n);
        inicio = clock();
        insertionSort(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,InsertionSort,Aleatorio,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- crescente --------
        gerarCrescente(vetor, n);
        inicio = clock();
        insertionSort(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,InsertionSort,Crescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- decrescente --------
        gerarDecrescente(vetor, n);
        inicio = clock();
        insertionSort(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,InsertionSort,Decrescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // Shell Sort
        // -------- aleatório do arquivo --------
        carregarVetor(nomeArquivo, vetor, n);
        inicio = clock();
        shellSort(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,ShellSort,Aleatorio,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- crescente --------
        gerarCrescente(vetor, n);
        inicio = clock();
        shellSort(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,ShellSort,Crescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- decrescente --------
        gerarDecrescente(vetor, n);
        inicio = clock();
        shellSort(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,ShellSort,Decrescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // Selection Sort
        // -------- aleatório do arquivo --------
        carregarVetor(nomeArquivo, vetor, n);
        inicio = clock();
        selectionSort(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,SelectionSort,Aleatorio,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- crescente --------
        gerarCrescente(vetor, n);
        inicio = clock();
        selectionSort(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,SelectionSort,Crescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- decrescente --------
        gerarDecrescente(vetor, n);
        inicio = clock();
        selectionSort(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,SelectionSort,Decrescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // Heap Sort
        // -------- aleatório do arquivo --------
        carregarVetor(nomeArquivo, vetor, n);
        inicio = clock();
        heapSort(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,HeapSort,Aleatorio,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- crescente --------
        gerarCrescente(vetor, n);
        inicio = clock();
        heapSort(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,HeapSort,Crescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- decrescente --------
        gerarDecrescente(vetor, n);
        inicio = clock();
        heapSort(vetor, n);
        fim = clock();
        fprintf(arquivo, "%d,HeapSort,Decrescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // Merge Sort
        // -------- aleatório do arquivo --------
        carregarVetor(nomeArquivo, vetor, n);
        inicio = clock();
        MergeSort(vetor,0, n);
        fim = clock();
        fprintf(arquivo, "%d,MergeSort,Aleatorio,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- crescente --------
        gerarCrescente(vetor, n);
        inicio = clock();
        MergeSort(vetor,0, n);
        fim = clock();
        fprintf(arquivo, "%d,MergeSort,Crescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // -------- decrescente --------
        gerarDecrescente(vetor, n);
        inicio = clock();
        MergeSort(vetor,0, n);
        fim = clock();
        fprintf(arquivo, "%d,MergeSort,Decrescente,%.4f\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);


        free(vetor);
    }

    fclose(arquivo);
    printf("Execucao concluida! Resultados salvos em tempos_ordenacao.csv\n");
    return 0;
}
