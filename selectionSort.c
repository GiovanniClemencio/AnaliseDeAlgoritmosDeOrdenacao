void selectionSort(int * vetor, int tamanho){
    int contExt, contInt, menor, indexacao;
    for(contExt = 0; contExt < tamanho; contExt++){
        menor = vetor[contExt];
        indexacao = contExt;
        for(contInt = contExt + 1; contInt < tamanho; contInt++){
            if(vetor[contInt] < menor){
                menor = vetor[contInt];
                indexacao = contInt;
            }
        }
        vetor[indexacao] = vetor[contExt];
        vetor[contExt] = menor;
    }
}
