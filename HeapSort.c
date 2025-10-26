#include <stdio.h>

// função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// max_heapify garante a propriedade de heap a partir de um índice i
void max_heapify(int *vetor, int n, int i) {
    int esq = 2 * i + 1;  // filho esquerdo
    int dir = 2 * i + 2;  // filho direito
    int maior = i;

    // se o filho esquerdo é maior que a raiz
    if (esq < n && vetor[esq] > vetor[maior])
        maior = esq;

    // se o filho direito é maior que o "maior" atual
    if (dir < n && vetor[dir] > vetor[maior])
        maior = dir;

    // se o maior não é a raiz
    if (maior != i) {
        swap(&vetor[i], &vetor[maior]);
        max_heapify(vetor, n, maior);
    }
}

// build_max_heap constrói um heap máximo a partir do vetor
void build_max_heap(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(A, n, i);
    }
}

void heapSort(int *vetor, int n) {
    build_max_heap(vetor, n);

    for (int i = n - 1; i > 0; i--) {
        // troca o maior (raiz) com o último elemento
        swap(&vetor[0], &vetor[i]);

        // restaura o heap na raiz, considerando tamanho reduzido
        max_heapify(vetor, i, 0);
    }
}
