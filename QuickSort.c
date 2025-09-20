// pivo no inicio
int particionarInicio(int *vetor, int ini, int fim) {
    int pivo = vetor[ini];
    int i = ini, j = fim;

    while (i < j) {
        while (i < j && vetor[j] >= pivo) j--; // anda do fim pra trás
        if (i < j) vetor[i++] = vetor[j];

        while (i < j && vetor[i] <= pivo) i++; // anda do inicio pra frente
        if (i < j) vetor[j--] = vetor[i];
    }

    vetor[i] = pivo; // coloca o pivo na posição correta
    return i;
}

int particionarMeio(int *vetor, int ini, int fim) {
    int meio = (ini + fim) / 2;

    // troca o do meio com o primeiro
    int aux = vetor[meio];
    vetor[meio] = vetor[ini];
    vetor[ini] = aux;

    return particionarInicio(vetor, ini, fim);
}

int* quickSortInicio(int *vetor, int ini, int fim) {
    if (ini < fim) {
        int pos = particionarInicio(vetor, ini, fim);
        quickSortInicio(vetor, ini, pos - 1);
        quickSortInicio(vetor, pos + 1, fim);
    }
    return vetor;
}

int* quickSortMeio(int *vetor, int ini, int fim) {
    if (ini < fim) {
        int pos = particionarMeio(vetor, ini, fim);
        quickSortMeio(vetor, ini, pos - 1);
        quickSortMeio(vetor, pos + 1, fim);
    }
    return vetor;
}
