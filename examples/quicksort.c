#include <stdio.h>

// Função utilitária para trocar dois elementos de lugar
// Usamos ponteiros para alterar os valores originais na memória
void trocar(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/*
  Função de Particionamento (Lomuto Partition Scheme)
  Objetivo:
  1. Escolhe o último elemento como pivô.
  2. Coloca o pivô na sua posição correta no array ordenado.
  3. Coloca todos os menores que o pivô à esquerda.
  4. Coloca todos os maiores que o pivô à direita.
*/
int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto]; // O pivô é o último elemento
    int i = (baixo - 1);  // Índice do menor elemento

    for (int j = baixo; j < alto ; j++) {
        // Se o elemento atual for menor que o pivô
        if (arr[j] < pivo) {
            i++; // Incrementa o índice do menor elemento
            trocar(&arr[i], &arr[j]);
        }
    }
    // Coloca o pivô na posição correta (após o último menor encontrado)
    trocar(&arr[i + 1], &arr[alto]);
    
    return (i + 1); // Retorna o índice onde o pivô parou
}

// Função principal do QuickSort
void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        // pi é o índice de particionamento (Partition Index)
        // Após esta chamada, arr[pi] está na posição correta e definitiva
        int pi = particionar(arr, baixo, alto);

        // Ordena os elementos separadamente antes e depois da partição
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

// Função utilitária para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    imprimirArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("\nArray ordenado:\n");
    imprimirArray(arr, n);

    return 0;
}