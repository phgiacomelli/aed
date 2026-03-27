#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize);

int main() {
    int acc1[] = {1,2,3};
    int acc2[] = {3,2,1};
    int *accounts[2];
    int accountsColSize = 3;
    int accountsSize = 2;

    accounts[0] = acc1;
    accounts[1] = acc2;

    int result = maximumWealth(accounts,accountsSize,&accountsColSize);
    printf("%d", result);
    return 0;
}

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int maior = 0, sum;
    for(int i=0; i<accountsSize;i++){
        sum = 0;

        for(int j=0; j<*accountsColSize;j++)
            sum+=accounts[i][j];

        if (sum>maior)
            maior = sum;
    }
    return maior;
}