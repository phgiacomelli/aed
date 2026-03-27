#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine);

int main() {
    char ransomNote[] = "aa";
    char magazine[] = "aab";
    bool result = canConstruct(ransomNote, magazine);
    return 0;
}

bool canConstruct(char* ransomNote, char* magazine) {
    if (strcmp(magazine, ransomNote) == 0)
        return true;

    int len;
    for (int j = 0; magazine[j] != '\0'; j++) {
        for (int i = 0; ransomNote[i] != '\0'; i++) {
            if (magazine[j] == ransomNote[i])
            {
                len = strlen(ransomNote);
                for (int k = i; k < len; k++)
                    ransomNote[k] = ransomNote[k+1]; 

                break;
            }
            
        }
    }

    if (strlen(ransomNote) == 0)
        return true;
    
    return false;
}