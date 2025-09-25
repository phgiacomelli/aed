#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(int x);

int main() {
    if (isPalindrome(-2147483648)) {
        printf("Palindromo\n");
    }

    
    return 0;
}

// 0ms
bool isPalindrome(int x) {
    char str[15];
    sprintf(str, "%d", x); 
    int len = strlen(str);

    for(int i = 0; i < len/2; i++)
        if(str[i] != str[len - 1 -i])
            return false;
        

    return true;
}

// ======= Solução sem sprintf ====
// 23ms

// bool isPalindrome(int x) {
//     int *nums;
//     float quant = 0.0;
//     nums = (int *)malloc(sizeof(int));

//     if (x < 0) {
//         return false;
//     } else {
//         do {
//             nums = (int *)realloc(nums, (quant + 1) * sizeof(int));
//             *(nums + (int)quant) = x % 10;
//             quant++;
//             x /= 10;
//         } while (x != 0);

//         for (int i = 0; i < quant / 2; i++)
//             if (*(nums + i) != *(nums + (((int)quant - 1) - i)))
//                 return false;

//         return true;
//     }
// }