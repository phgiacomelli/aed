// M2 - Paulo Henrique Anesi Giacomelli

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara(int a, int b) {
    char strA[50], strB[50];

    sprintf(strA, "%d%d", a, b);
    sprintf(strB, "%d%d", b, a);

    return strcmp(strA, strB);
}

void troca(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int dividir(int arr[], int left, int right) {
    int pivo = arr[right];  // usei o pivo como sendo o ulitmo elemento
    int index = left - 1;

    for (int i = left; i < right; i++) {
        if (compara(arr[i], pivo) > 0) {
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

char* largestNumber(int* nums, int numsSize) {
    if (numsSize == 0)
        return NULL;

    quicksort(nums, 0, numsSize - 1);
    
    char* result = NULL;
    
    if (nums[0] == 0)
    {
        result = malloc(2*sizeof(char));
        result[0] = '\0';
        strcat(result, "0");
        return result;
    }
    
    result = (char*)malloc(numsSize * 1000 * sizeof(char));
    result[0] = '\0';
    char temp[15];
    temp[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        sprintf(temp, "%d", nums[i]);
        strcat(result, temp);
    }

    return result;
}

int main() {
    // int nums[] = {10, 2
    int nums[] = {3, 30, 34, 5, 9};
    // int nums[] = {0};
    // int nums[] = {700000000,500000000};
    // int nums[] = {10,2};
    int size = sizeof(nums) / sizeof(nums[0]);

    char* result = largestNumber(nums, size);

    printf("Result: %s\n", result);

    free(result);
    return 0;
}