#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfSteps(int num);

int main() {

    int num = numberOfSteps(14);
    printf("%d",num);
    return 0;
}

int numberOfSteps(int num) {
    int steps = 0;
    while (num!=0)
    {
        if (num%2==0)
            num/=2;
        else
            num--;

        steps++;
    }
    return steps;
    
}