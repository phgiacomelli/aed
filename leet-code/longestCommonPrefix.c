#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main() {
    char* strs[] = {"flower", "flow", "flight"};
    printf("%s\n", longestCommonPrefix(strs, 3));

    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    
    char prefix[10] = "";
    int indexCurrentChar = 0;
    
    int i = 0;
    
    while (i < strsSize) {
        char currentChar = strs[i][indexCurrentChar];
        
        
    }
    
    for (int i = 0; i < strsSize; i++) {
    
    }

    // char* shortestWord = strs[0];
    // int shortestWordLen = strlen(strs[0]);
    // for (int k = 1; k < strsSize; k++) {
    //     if ((int)strlen(strs[k]) < shortestWordLen) {
    //         shortestWord = strs[k];
    //         shortestWordLen = strlen(strs[k]);
    //     }
    // }

    return "";
}