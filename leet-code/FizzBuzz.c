#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fizzBuzz(int n, int* returnSize);

int main() {
    int n = 15;
    int returnSize;
    char **answer = fizzBuzz(n, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf("%s\n",answer[i]);  

    free(answer);
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char **answer = (char **)malloc(n*sizeof(char *));
    *returnSize = n;
    for(int i = 1; i<=n;i++){
        if(i%5 == 0 && i%3==0){
            answer[i-1] = (char *)malloc(strlen("FizzBuzz")+1);
            strcpy(answer[i-1],"FizzBuzz");
        }
        else if(i%5 == 0){
            answer[i-1] = (char *)malloc(strlen("Buzz")+1);
            strcpy(answer[i-1],"Buzz");
        }
        else if(i%3==0){
            answer[i-1] = (char *)malloc(strlen("Fizz")+1);
            strcpy(answer[i-1],"Fizz");
        } else{
            char str[15];
            sprintf(str,"%d",i);
            answer[i-1] = (char *)malloc(strlen(str)+1);
            strcpy(answer[i-1],str);
        }
    }
    return answer;
}