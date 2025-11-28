#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
} Person;

typedef struct {
    Person* people;
    Person* top;
    Person* base;
    int limit;
} Stack;

bool isEmpty(Stack* stack) {
    return stack->top == stack->base;
}

bool isFull(Stack* stack) {
    return (stack->top - stack->base) >= stack->limit;
}

void Reset(Stack* stack, int limit) {
    if (stack->people != NULL)
        free(stack->people);

    stack->limit = limit;

    if (stack->limit > 0) {
        stack->people = (Person*)malloc(stack->limit * sizeof(Person));

        stack->base = stack->people;
        stack->top = stack->people;
    } else {
        stack->people = NULL;
        stack->base = NULL;
        stack->top = NULL;
    }
}

bool Push(Stack* stack, Person* person) {
    if (isFull(stack))
        return false;

    *(stack->top) = *person;

    stack->top++;
}

int main() {
    return 0;
}