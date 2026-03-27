// Paulo Henrique Anesi Giacomelli - M2

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n);

int main() {
    int flowerbed[] = {1, 0, 0, 0, 1};
    int flowerbedSize = 5;
    int n = 1;

    bool result = canPlaceFlowers(flowerbed, flowerbedSize, n);

    printf("%s\n", result ? "true" : "false");

    return 0;
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (flowerbed == NULL || flowerbedSize <= 0)
        return false;

    bool leftEmpty = false, rightEmpty = false;
    int flowersAccepted = 0;
    for (int i = 0; i < flowerbedSize; i++) {
        if (i == 0 || flowerbed[i - 1] == 0)
            leftEmpty = true;

        if (i == flowerbedSize - 1 || flowerbed[i + 1] == 0)
            rightEmpty = true;

        if (rightEmpty && leftEmpty && flowerbed[i]==0) {
            flowerbed[i] = 1;
            flowersAccepted++;
        }

        leftEmpty = rightEmpty = false;
    }

    return flowersAccepted >= n;
}
