#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* restoreString(char* s, int* indices, int indicesSize);

int main() {
    char* s = "codeleet";
    int indices[] = {4, 5, 6, 7, 0, 2, 1, 3};
    int indicesSize = 8;

    char* result = restoreString(s, indices, indicesSize);

    printf("%s\n",result);

    return 0;
}

char* restoreString(char* s, int* indices, int indicesSize) {
    char *result = (char *)malloc((indicesSize+1)*sizeof(char));

    result[indicesSize] = '\0'; 
    
    for (int i = 0; i < indicesSize; i++)
            result[indices[i]] = s[i];
    

    return result;
}
