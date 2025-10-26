void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

void quickSortInicio(int *vetor, int ini, int fim) {
    if (ini < fim) {
        int pos = particionarInicio(vetor, ini, fim);

        quickSortInicio(vetor, ini, pos);
        quickSortInicio(vetor, pos + 1, fim);
    }
}


int particionarMeio(int *vetor, int ini, int fim) {
    int meio = (ini + fim) / 2;

    // troca o do meio com o primeiro
    trocar(&vetor[meio], &vetor[ini]);

    return particionarInicio(vetor, ini, fim);
}


void quickSortMeio(int *vetor, int ini, int fim) {
    if (ini < fim) {
        int pos = particionarMeio(vetor, ini, fim);
        quickSortMeio(vetor, ini, pos );
        quickSortMeio(vetor, pos + 1, fim);
    }
}
