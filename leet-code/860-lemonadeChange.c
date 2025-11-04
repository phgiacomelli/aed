#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool lemonadeChange(int* bills, int billsSize);

int main() {
    // int bills[] = {5, 5, 10, 10, 20};
    int bills[] = {5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5};
    int billsSize = 20;

    bool result = lemonadeChange(bills, billsSize);

    printf("%s\n", result ? "true" : "false");

    return 0;
}

bool lemonadeChange(int* bills, int billsSize) {
    int five = 0, ten = 0;
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            five++;
        } else {
            if (five > 0 && bills[i] == 10) {
                five--;
                ten++;
            } else if (bills[i] == 20 && (five > 2 || ten > 0)) {
                if (five > 2 && ten < 1) {
                    five -= 3;
                } else if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else {
                    return false;
                }

            } else {
                return false;
            }
        }
    }

    return true;
}