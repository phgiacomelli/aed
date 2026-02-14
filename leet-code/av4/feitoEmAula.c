// M2 - Paulo Henrique Anesi Giacomelli

// Ideia:
// Ordenar o vetor em ordem crescente.
// Comparar os valores da seguinte forma:
// vou olhar sempre o digito mais a esquerda no numero, por exemplo: 10, 9, 20, 34, 33
//              Olho para o 1, 9, 2 e 3, o que for maior, é o numero que vou colocar na string (o numero inteiro, nao apenas o digito mais a esquerda)
// Logo temos na string o 9;
// Vamos verificando isso ate achar numeros que tenham o digito mais a esquerda igual.
// neste caso, teriamos o 34 e 33, logo olhamos o 2o digito, qual é maior, o 4, entao adicionamos o 34 e depois o 33
// 934332010

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* intToSrt(int num) {
    char* str = (char*)malloc(12 * sizeof(char));
    sprintf(str, "%d", num); 
    return str;
}

void troca(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int dividir(int arr[], int left, int right) {
    // int mid = arr[left - ((left - right) / 2)];
    int pivo = arr[right]; // usei o pivo como sendo o ulitmo elemento
    int index = left - 1;

    for (int i = left; i < right; i++) {
        if (arr[i] > pivo) {
            index++;
            troca(&arr[index], &arr[i]);
        }
    }

    troca(&arr[index + 1], &arr[right]);

    return index + 1;
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pivoIndex = dividir(arr, left, right);

        quicksort(arr, left, pivoIndex - 1);
        quicksort(arr, pivoIndex + 1, right);
    }
}

char* largestNumber(int* nums, int numsSize){
    char *result = (char*)malloc(1000 * sizeof(char)); 

    quicksort(nums, 0, numsSize - 1);

    for (int i = 0; i < numsSize; i++)
    {
        
    }
    


    
    return result;
}

int main() {
    // int nums[] = {10, 2};
    int nums[] = {3, 30, 34, 5, 9};
    int size = sizeof(nums) / sizeof(nums[0]);

    char* result = largestNumber(nums, size);


    printf("\n\nResult: %s", result);

    

    return 0;