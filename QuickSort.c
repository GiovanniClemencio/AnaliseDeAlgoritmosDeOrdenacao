#define MAX_STACK_SIZE 500000

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// particionamento que usa o primeiro elemento como pivô
int particionarInicio(int *vetor, int ini, int fim) {
    int pivo = vetor[ini];
    int i = ini - 1;
    int j = fim + 1;

    while (1) {
        do {
            i++;
        } while (vetor[i] < pivo);

        do {
            j--;
        } while (vetor[j] > pivo);

        if (i >= j) {
            return j;
        }

        trocar(&vetor[i], &vetor[j]);
    }
}

// particionamento que usa o elemento do meio como pivô
int particionarMeio(int *vetor, int ini, int fim) {
    int meio = (ini + fim) / 2;

    // troca o do meio com o primeiro
    trocar(&vetor[meio], &vetor[ini]);

    return particionarInicio(vetor, ini, fim);
}

// Função para Quicksort Iterativo (Pivô no Início)
void quickSortInicio(int *vetor, int n) {
    int stack[MAX_STACK_SIZE];
    int top = -1; // topo da pilha

    // empilha (push) os índices do array principal
    stack[++top] = 0;   // início
    stack[++top] = n - 1; // fim

    // continua enquanto a pilha não estiver vazia
    while (top >= 0) {
        // desempilha (pop) os limites do subvetor
        int fim = stack[top--];
        int ini = stack[top--];

        // particiona o subvetor e obtém a posição final do pivô
        int pos = particionarInicio(vetor, ini, fim);

        // se houver elementos à esquerda do pivô
        if (pos > ini) {
            // empilha os limites do subvetor da esquerda (ini, pos)
            stack[++top] = ini;
            stack[++top] = pos;
        }

        // se houver elementos à direita do pivô
        if (pos + 1 < fim) {
            // empilha os limites do subvetor da direita (pos + 1, fim)
            stack[++top] = pos + 1;
            stack[++top] = fim;
        }
    }
}

// Função para Quicksort Iterativo (Pivô no Meio)
void quickSortMeio(int *vetor, int n) {
    int stack[MAX_STACK_SIZE];
    int top = -1; // topo da pilha

    // empilha (push) os índices do array principal
    stack[++top] = 0;   // início
    stack[++top] = n - 1; // fim (

    // continua enquanto a pilha não estiver vazia
    while (top >= 0) {
        // desempilha (pop) os limites do subvetor
        int fim = stack[top--];
        int ini = stack[top--];

        // particiona o subvetor usando o pivô do meio
        int pos = particionarMeio(vetor, ini, fim);

        // se houver elementos à esquerda do pivô
        if (pos > ini) {
            // empilha os limites do subvetor da esquerda (ini, pos)
            stack[++top] = ini;
            stack[++top] = pos;
        }

        // se houver elementos à direita do pivô
        if (pos + 1 < fim) {
            // empilha os limites do subvetor da direita (pos + 1, fim)
            stack[++top] = pos + 1;
            stack[++top] = fim;
        }
    }
}
