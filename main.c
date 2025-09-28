#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* populaVetorAleartorio(int **vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % (int)(tamanho + 0.7*tamanho);
    }
    return;
}

int* populaVetorDecrescente(int **vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = tamanho - i;
    }
    return;
}

int* populaVetorCrescente(int **vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        vetor[i] = i;
    }
    return;
}

void chamadaBubbleClassico(int **vetor, int tamanho, double *tempos, int pos){
    clock_t inicio, fim;
    int resultado[tamanho];
    double tempo;
    // imprime vetor
    inicio = clock();
    resultado[tamanho] = BubbleSortClassico(*vetor, tamanho);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    //imprimir vetor resultado
    printf("Tempo: %f\n", tempo);
    tempos[pos] = tempo;
}

void chamadaBubbleMelhorado(int **vetor, int tamanho, double *tempos, int pos){
    clock_t inicio, fim;
    int resultado[tamanho];
    double tempo;
    // imprime vetor
    inicio = clock();
    resultado[tamanho] = BubbleSortMelhorado(*vetor, tamanho);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    //imprimir vetor resultado
    printf("Tempo: %f\n", tempo);
    tempos[pos] = tempo;
}

void chamadaQuickSortInicio(int **vetor, int ini, int fim, double *tempos, int pos){
    clock_t inicio, fin;
    int resultado[fim];
    double tempo;
    // imprime vetor
    inicio = clock();
    resultado[fim] = quickSortInicio(*vetor, ini, fim);
    tempo = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    //imprimir vetor resultado
    printf("Tempo: %f\n", tempo);
    tempos[pos] = tempo;
}

void chamadaQuickSortMeio(int **vetor, int ini, int fim, double *tempos, int pos){
    clock_t inicio, fin;
    int resultado[fim];
    double tempo;
    // imprime vetor
    inicio = clock();
    resultado[fim] = quickSortMeio(*vetor, ini, fim);
    tempo = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    //imprimir vetor resultado
    printf("Tempo: %f\n", tempo);
    tempos[pos] = tempo;
}

int main(){
    srand(time(NULL));

    double tempos[81];
    /*int seletor = 0, tamanhoPequeno = 1000, tamanhoMedio = 5000, tamanhoGrande = 10000;

    int vetorPequenoAleartorio[tamanhoPequeno], vetorPequenoDecrescente[tamanhoPequeno], vetorPequenoCrescente[tamanhoPequeno];
    int vetorMedioAleartorio[tamanhoMedio], vetorMedioDecrescente[tamanhoMedio], vetorMedioCrescente[tamanhoMedio];
    int vetorGrandeAleartorio[tamanhoGrande], vetorGrandeDecrescente[tamanhoGrande], vetorGrandeCrescente[tamanhoGrande];

    populaVetorAleartorio(&vetorPequenoAleartorio, tamanhoPequeno);
    populaVetorCrescente(&vetorPequenoDecrescente, tamanhoPequeno);
    populaVetorDecrescente(&vetorPequenoCrescente, tamanhoPequeno);

    populaVetorAleartorio(&vetorMedioAleartorio, tamanhoMedio);
    populaVetorCrescente(&vetorMedioDecrescente, tamanhoMedio); // TODO: Implementar corretamente esses vetores nas chamadas e arrumar o vetor de tempos
    populaVetorDecrescente(&vetorMedioCrescente, tamanhoMedio);

    populaVetorAleartorio(&vetorGrandeAleartorio, tamanhoGrande);
    populaVetorCrescente(&vetorGrandeDecrescente, tamanhoGrande);
    populaVetorDecrescente(&vetorGrandeCrescente, tamanhoGrande);

    printf("-=-= ANALISE ASSINTOTICA =-=-\n\n");
    while(seletor != 99){
        printf("Selecione o algoritimo que deseja executar: \n");
        printf("1 - Bubble Sort simples\n");
        printf("2 - Bubble Sort melhorado\n");
        printf("3 - Quick Sort (pivo = primeiro da lista)\n");
        printf("4 - Quick Sort (pivo = centro da lista)\n");
        printf("5 - Insertion Sort\n");
        printf("6 - Shell Sort\n");
        printf("7 - Selection Sort\n");
        printf("8 - Heap Sort\n");
        printf("9 - Merge Sort\n");
        printf("10 - TODOS\n");
        printf("0 - Sair");

        scanf("%d", &seletor);

        switch(seletor){
            case 1:
                printf("DEBUG: Bubble Simples\n");
                printf("-=-=Vetor Pequeno=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubbleClassico(&vetorPequenoAleartorio, tamanhoPequeno, tempos, 0);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubbleClassico(&vetorPequenoAleartorio, tamanhoPequeno, tempos, 1);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubbleClassico(&vetorPequenoAleartorio, tamanhoPequeno, tempos, 2);

                printf("-=-=Vetor Medio=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubbleClassico(&vetorMedioAleartorio, tamanhoMedio, tempos, 3);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubbleClassico(&vetorMedioAleartorio, tamanhoMedio, tempos, 4);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubbleClassico(&vetorMedioAleartorio, tamanhoMedio, tempos, 5);

                printf("-=-=Vetor Grande=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubbleClassico(&vetorGrandeAleartorio, tamanhoGrande, tempos, 6);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubbleClassico(&vetorGrandeAleartorio, tamanhoGrande, tempos, 7);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubbleClassico(&vetorGrandeAleartorio, tamanhoGrande, tempos, 8);

                printf("\nTempos finais: ");
                for(int i = 0; i < 9; i++) printf("%f ", tempos[i]);
                break;
            case 2:
                printf("DEBUG: Bubble Melhorado\n");
                printf("-=-=Vetor Pequeno=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubbleMelhorado(&vetorPequenoAleartorio, tamanhoPequeno, tempos, 0);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubbleMelhorado(&vetorPequenoAleartorio, tamanhoPequeno, tempos, 1);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubbleMelhorado(&vetorPequenoAleartorio, tamanhoPequeno, tempos, 2);

                printf("-=-=Vetor Medio=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubbleMelhorado(&vetorMedioAleartorio, tamanhoMedio, tempos, 3);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubbleMelhorado(&vetorMedioAleartorio, tamanhoMedio, tempos, 4);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubbleMelhorado(&vetorMedioAleartorio, tamanhoMedio, tempos, 5);

                printf("-=-=Vetor Grande=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubbleMelhorado(&vetorGrandeAleartorio, tamanhoGrande, tempos, 6);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubbleMelhorado(&vetorGrandeAleartorio, tamanhoGrande, tempos, 7);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubbleMelhorado(&vetorGrandeAleartorio, tamanhoGrande, tempos, 8);

                printf("\nTempos finais: ");
                for(int i = 0; i < 9; i++) printf("%f ", tempos[i]);
                break;
            case 3:
                printf("DEBUG: QuickSort pivo no comeco\n");
                printf("-=-=Vetor Pequeno=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaQuickSortInicio(&vetorPequenoAleartorio, 0, tamanhoPequeno, tempos, 0);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaQuickSortInicio(&vetorPequenoAleartorio, 0, tamanhoPequeno, tempos, 1);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaQuickSortInicio(&vetorPequenoAleartorio, 0, tamanhoPequeno, tempos, 2);

                printf("-=-=Vetor Medio=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorMedioAleartorio, tamanhoMedio);
                chamadaQuickSortInicio(&vetorMedioAleartorio, 0, tamanhoMedio, tempos, 3);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaQuickSortInicio(&vetorMedioAleartorio, 0, tamanhoMedio, tempos, 4);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaQuickSortInicio(&vetorMedioAleartorio, 0, tamanhoMedio, tempos, 5);

                printf("-=-=Vetor Grande=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaQuickSortInicio(&vetorGrandeAleartorio, 0, tamanhoGrande, tempos, 6);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaQuickSortInicio(&vetorGrandeAleartorio, 0, tamanhoGrande, tempos, 7);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaQuickSortInicio(&vetorGrandeAleartorio, 0, tamanhoGrande, tempos, 8);

                printf("\nTempos finais: ");
                for(int i = 0; i < 9; i++) printf("%f ", tempos[i]);
                break;
            case 4:
                printf("DEBUG: QuickSort pivo no meio\n");
                printf("-=-=Vetor Pequeno=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaQuickSortMeio(&vetorPequenoAleartorio, 0, tamanhoPequeno, tempos, 0);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaQuickSortMeio(&vetorPequenoAleartorio, 0, tamanhoPequeno, tempos, 1);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaQuickSortMeio(&vetorPequenoAleartorio, 0, tamanhoPequeno, tempos, 2);

                printf("-=-=Vetor Medio=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorMedioAleartorio, tamanhoMedio);
                chamadaQuickSortMeio(&vetorMedioAleartorio, 0, tamanhoMedio, tempos, 3);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaQuickSortMeio(&vetorMedioAleartorio, 0, tamanhoMedio, tempos, 4);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaQuickSortMeio(&vetorMedioAleartorio, 0, tamanhoMedio, tempos, 5);

                printf("-=-=Vetor Grande=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaQuickSortMeio(&vetorGrandeAleartorio, 0, tamanhoGrande, tempos, 6);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaQuickSortMeio(&vetorGrandeAleartorio, 0, tamanhoGrande, tempos, 7);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorGrandeAleartorio, tamanhoGrande);

                chamadaQuickSortMeio(&vetorGrandeAleartorio, 0, tamanhoGrande, tempos, 8);

                printf("\nTempos finais: ");
                for(int i = 0; i < 9; i++) printf("%f ", tempos[i]);
                break;
            case 5:
                printf("DEBUG: Insertion\n");
                printf("-=-=Vetor Pequeno=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 0);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 1);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 2);

                printf("-=-=Vetor Medio=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 3);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 4);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 5);

                printf("-=-=Vetor Grande=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 6);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 7);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 8);

                printf("\nTempos finais: ");
                for(int i = 0; i < 9; i++) printf("%f ", tempos[i]);
                break;
            case 6:
                printf("DEBUG: Shell\n");
                printf("-=-=Vetor Pequeno=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 0);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 1);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 2);

                printf("-=-=Vetor Medio=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 3);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 4);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 5);

                printf("-=-=Vetor Grande=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 6);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 7);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 8);

                printf("\nTempos finais: ");
                for(int i = 0; i < 9; i++) printf("%f ", tempos[i]);
                break;
            case 7:
                printf("DEBUG: Selection\n");
                printf("-=-=Vetor Pequeno=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 0);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 1);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 2);

                printf("-=-=Vetor Medio=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 3);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 4);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 5);

                printf("-=-=Vetor Grande=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 6);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 7);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 8);

                printf("\nTempos finais: ");
                for(int i = 0; i < 9; i++) printf("%f ", tempos[i]);
                break;
            case 8:
                printf("DEBUG: Heap\n");
                printf("-=-=Vetor Pequeno=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 0);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 1);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 2);

                printf("-=-=Vetor Medio=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 3);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 4);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 5);

                printf("-=-=Vetor Grande=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 6);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 7);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 8);

                printf("\nTempos finais: ");
                for(int i = 0; i < 9; i++) printf("%f ", tempos[i]);
                break;
            case 9:
                printf("DEBUG: Merge\n");
                printf("-=-=Vetor Pequeno=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 0);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 1);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorPequenoAleartorio, tamanhoPequeno);
                chamadaBubble(&vetorPequenoAleartorio, tempos, 2);

                printf("-=-=Vetor Medio=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 3);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 4);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorMedioAleartorio, tamanhoMedio);
                chamadaBubble(&vetorMedioAleartorio, tempos, 5);

                printf("-=-=Vetor Grande=-=-\n");
                printf("Aleartorio -");
                populaVetorAleartorio(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 6);

                printf("Ordem crescente -");
                populaVetorCrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 7);

                printf("Ordem decrescente -");
                populaVetorDecrescente(&vetorGrandeAleartorio, tamanhoGrande);
                chamadaBubble(&vetorGrandeAleartorio, tempos, 8);

                printf("\nTempos finais: ");
                for(int i = 0; i < 9; i++) printf("%f ", tempos[i]);
                break;
            case 10:
                printf("DEBUG: ALL\n");
                break;
            case 0:
                printf("Bye bye\n");
                seletor = 99;
                break;
        }
    }*/

    return 0;
}
