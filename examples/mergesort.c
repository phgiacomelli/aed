#include <stdio.h>
#include <stdlib.h>

// Função para intercalar (merge) dois sub-arrays
// O primeiro sub-array é arr[esquerda..meio]
// O segundo sub-array é arr[meio+1..direita]
void merge(int arr[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Cria arrays temporários
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copia dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    // Intercala os arrays temporários de volta em arr[esquerda..direita]
    i = 0; // Índice inicial do primeiro sub-array
    j = 0; // Índice inicial do segundo sub-array
    k = esquerda; // Índice inicial do array intercalado

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Libera a memória alocada
    free(L);
    free(R);
}

// Função principal do Merge Sort
void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        // Encontra o ponto médio
        // (esquerda + direita) / 2 pode causar overflow em grandes inteiros
        // a forma abaixo evita isso:
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);

        // Intercala as duas metades ordenadas
        merge(arr, esquerda, meio, direita);
    }
}

void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int tamanho_arr = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    imprimirArray(arr, tamanho_arr);

    mergeSort(arr, 0, tamanho_arr - 1);

    printf("\nArray ordenado:\n");
    imprimirArray(arr, tamanho_arr);

    return 0;
}