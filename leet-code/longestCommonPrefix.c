#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main() {
    // char* strs[] = {"flower", "flow", "flight"};
    char* strs[] = {"carro", "carga", "carregador"};
    char *prefix = longestCommonPrefix(strs, 3);
    printf("%s\n", prefix);

    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    char *prefix = (char *)malloc(sizeof(char));
    int indexCurrentChar = 0;
    bool isAccepted = true;
    char temp;
    
    while (1) {
        if (strs[0][indexCurrentChar] == '\0')
            break;
        
        temp = strs[0][indexCurrentChar];
        for (int i = 0; i < strsSize; i++) {
            if (strs[i][indexCurrentChar] != temp) {
                isAccepted = false;
                break;
            }
        }
        
        if (isAccepted) {
            prefix = (char *)realloc(prefix, (indexCurrentChar+2)*sizeof(char));
            prefix[indexCurrentChar] = temp;
            indexCurrentChar++;
        } else {
            break;
        }
    }
    prefix[indexCurrentChar] = '\0';

    return prefix;
}