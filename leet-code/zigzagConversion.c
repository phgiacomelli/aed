#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows);

int main() {
    char s[] = "PAYPALISHIRING";
    // char s[] = "AB";
    int numRows = 3;

    char* result = convert(s, numRows);

    printf("%s", result);

    return 0;
}

char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1)
        return s;

    char** result = (char**)malloc(numRows * sizeof(char*));
    int *indices = (int *)malloc(numRows * sizeof(int));

    for (int j = 0; j < numRows; j++){
        result[j] = (char*)malloc((len+1)*sizeof(char));
        *result[j] = '\0';
        *(indices+j) = 0;
    }

    bool crescente = true;
    int i = 0, strI = 0;
    while (strI < len) {
        
        if (i == (numRows - 1))
            crescente = false;
        else if (i == 0)
            crescente = true;

        // int currentIndex = strlen(result[i]);
        int *currentIndex = indices+i;

        // result[i] = (char*)realloc(result[i], (currentIndex + 1) * sizeof(char));
        result[i][*currentIndex] = s[strI];
        result[i][*(currentIndex)+1] = '\0';
        *(currentIndex)+=1;
        i = crescente ? i + 1 : i - 1;

        strI++;
    }

    char* res = (char*)malloc((len+1) * sizeof(char));
    int indice = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; result[i][j] != '\0'; j++) {
            res[indice] = result[i][j];
            indice++;
        }
    }
    res[indice] = '\0';

    return res;
}

//  0   0   0
//  1 1 1 1 1
//  2   2   2