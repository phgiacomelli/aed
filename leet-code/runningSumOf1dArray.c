#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* runningSum(int* nums, int numsSize, int* returnSize);

int main() {
    int nums[] = {1, 2, 3, 4};

    int returnSize = 0;
    int* result;
    result = runningSum(&nums[0], 4, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", *(result + i));
    }

    return 0;
}

int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* result;
    result = (int*)malloc(numsSize * sizeof(int));
    int limit = 0, sum = 0;
    for (int i = 0; *returnSize < numsSize; i++) {
        if (i > limit) {
            limit++;
            i = 0;
            *(result + *returnSize) = sum;
            sum = 0;
            (*returnSize)++;
        }
        sum += nums[i];
    }
    return result;
}