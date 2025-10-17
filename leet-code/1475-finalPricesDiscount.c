#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* finalPrices(int* prices, int pricesSize, int* returnSize);

int main() {
    // int prices[] = {1,2,3,4,5};
    int prices[] = {8, 4, 6, 2, 3};
    int pricesSize = 5, returnSize;

    int* result = finalPrices(prices, pricesSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}

// int* finalPrices(int* prices, int pricesSize, int* returnSize) {
//     if (pricesSize < 1)
//         return NULL;

//     *returnSize = pricesSize;
//     int* result = (int*)malloc(pricesSize * sizeof(int));

//     for (int i = pricesSize - 1; i >= 0; i++) {
//         for (int j = i - 1; j >= 0; j++) {
//             if (prices[j] < prices[i]) {
//                 result[i] = prices[i] - prices[j];

//             }
//         }
//     }

//     return result;
// }

int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    if (pricesSize < 1)
        return NULL;

    *returnSize = pricesSize;
    int* result = (int*)malloc(pricesSize * sizeof(int));

    for (int i = 0; i < pricesSize; i++) {
        result[i] = prices[i];
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[i] >= prices[j]) {
                result[i] = prices[i] - prices[j];
                j = pricesSize;
            }
        }
    }

    return result;
}