#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char brackets[(int)(10e3)];
    int top;
} Stack;

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top == (10e3) - 1;
}

void push(Stack* stack, char c) {
    if (isFull(stack))
        return;

    stack->brackets[++stack->top] = c;
}

char pop(Stack* stack) {
    if (isEmpty(stack))
        return '\0';

    char c = stack->brackets[stack->top--];
    return c;
}

bool isValid(char* s) {
    int len = strlen(s);

    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack)
        return false;
    stack->top = -1;

    for (int i = 0; i < len; i++) {
        char curr = s[i];

        if (curr == '(' || curr == '[' || curr == '{')
            push(stack, curr);

        else {
            if (isEmpty(stack))
                return false;

            char last = pop(stack);

            if ((last != '(' && curr == ')') || (last != '[' && curr == ']') || (last != '{' && curr == '}')) {
                free(stack);
                return false;
            }
        }
    }

    bool result = isEmpty(stack);

    free(stack);
    return result;
}

int main() {
    char str[] = "([])";
    bool result = isValid(str);
    return 0;
}