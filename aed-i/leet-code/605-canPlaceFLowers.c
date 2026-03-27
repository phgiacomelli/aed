#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n);

int main() {
    int flowerbed[] = {1, 0, 0, 0, 0, 0, 1};
    int flowerbedSize = 7, n = 1;

    bool result = canPlaceFlowers(flowerbed, flowerbedSize, n);
    if (result)
        printf("É possivel plantar %d flore(s)!", n);

    return 0;
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (flowerbedSize == 0 || flowerbed == NULL)
        return NULL;

    int flowersAccepted = 0;
    bool leftIsFree = false, rightIsFree = false;
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            leftIsFree = i == 0 || flowerbed[i - 1] != 1;
            rightIsFree = i == flowerbedSize - 1 || flowerbed[i + 1] != 1;

            if (leftIsFree && rightIsFree) {
                flowersAccepted++;
                flowerbed[i] = 1;
            }
        }
    }

    return n <= flowersAccepted;
}