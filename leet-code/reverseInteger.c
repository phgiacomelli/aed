#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse(int x);

int main() {
    int a = reverse(1534236469);

    return 0;
}

int reverse(int x) {
    signed int reverse = 0;
    while (x != 0) {
        reverse = (10*reverse) + x%10;
        x/=10;
    }

    return reverse;
}
