#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes);

int main() {
    int numRows = 6;
    int returnSize, *returnColumnSizes;

    int** result = generate(numRows, &returnSize, &returnColumnSizes);

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    if (numRows < 1)
        return NULL;

    *returnSize = numRows;
    int** result = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {
        result[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                result[i][j] = 1;
            else
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    return result;
}