#include <stdio.h>

// função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// max_heapify garante a propriedade de heap a partir de um índice i
void max_heapify(int A[], int n, int i) {
    int esq = 2 * i + 1;  // filho esquerdo
    int dir = 2 * i + 2;  // filho direito
    int maior = i;

    // se o filho esquerdo é maior que a raiz
    if (esq < n && A[esq] > A[maior])
        maior = esq;

    // se o filho direito é maior que o "maior" atual
    if (dir < n && A[dir] > A[maior])
        maior = dir;

    // se o maior não é a raiz
    if (maior != i) {
        swap(&A[i], &A[maior]);
        max_heapify(A, n, maior);
    }
}

// build_max_heap constrói um heap máximo a partir do vetor
void build_max_heap(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(A, n, i);
    }
}

void heap_sort(int A[], int n) {
    build_max_heap(A, n);

    for (int i = n - 1; i > 0; i--) {
        // troca o maior (raiz) com o último elemento
        swap(&A[0], &A[i]);

        // restaura o heap na raiz, considerando tamanho reduzido
        max_heapify(A, i, 0);
    }
}
