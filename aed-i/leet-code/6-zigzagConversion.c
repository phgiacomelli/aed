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
    free(result);

    return 0;
}

char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1)
        return s;

    char** strs= (char**)malloc(numRows * sizeof(char*));
    int* strsLen = (int *)malloc(numRows * sizeof(int));

    for (int j = 0; j < numRows; j++){
        strs[j] = (char*)malloc((len+1)*sizeof(char));
        *strs[j] = '\0';
        *(strsLen+j) = 0;
    }

    bool ascending = true;
    int i = 0, resultIndex = 0;
    while (resultIndex < len) {
        
        if (i == (numRows - 1))
            ascending = false;
        else if (i == 0)
            ascending = true;

        int *currentIndex = strsLen+i;

        strs[i][*currentIndex] = s[resultIndex];
        strs[i][++*(currentIndex)] = '\0';

        i = ascending ? i + 1 : i - 1;

        resultIndex++;
    }

    char* result = (char*)malloc((len+1) * sizeof(char));
    resultIndex = 0;
    for (int k = 0; k < numRows; k++) {
        for (int j = 0; strs[k][j] != '\0'; j++) {
            result[resultIndex] = strs[k][j];
            resultIndex++;
        }
        free(strs[k]);
    }
    result[resultIndex] = '\0';

    free(strs);
    free(strsLen);

    return result;
}
