#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int top;
    int length;
    int *arr;
} MyStack;

MyStack* myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    if (!stack)
        return NULL;
    
    stack->top=-1;
    stack->length=0;
    stack->arr = (int *)malloc(sizeof(int));

    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj
    obj->arr = (int *)realloc(obj->arr,(obj->length+1) * sizeof(int));

}

int myStackPop(MyStack* obj) {
}

int myStackTop(MyStack* obj) {
}

bool myStackEmpty(MyStack* obj) {
}

void myStackFree(MyStack* obj) {
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/

int main() {
    MyStack myStack = myStackCreate();
    myStack.push(1);
    myStack.push(2);
    myStack.top();    // return 2
    myStack.pop();    // return 2
    myStack.empty();  // return False

    return 0;
}