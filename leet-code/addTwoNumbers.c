#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum1 = 0, sum2 = 0;
    int fator = 1;
    for (struct ListNode* i1 = l1; i1 != NULL; i1 = i1->next) {
        sum1 += i1->val * fator;
        fator *= 10;
    }
    fator = 1;
    for (struct ListNode* i2 = l2; i2 != NULL; i2 = i2->next) {
        sum2 += i2->val * fator;
        fator *= 10;
    }

    int sum = sum1 + sum2;
    struct ListNode *head = NULL, *last = NULL;
    if (sum == 0)
    {
        struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val = sum;
        new->next = NULL;
        head = new;
    }
    
    while (sum != 0) {
        struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));

        new->val = sum % 10;
        sum/=10;
        new->next = NULL;

        if (head == NULL) {
            head = new;
            last = new;
        } else {
            last->next = new;
            last = new;
        }
    }

    return head;
}

struct ListNode* createList(int* arr, int size) {

    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;

    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        struct ListNode* new = malloc(sizeof(struct ListNode));
        new->val = arr[i];
        new->next = NULL;
        current->next = new;
        current = new;
    }

    return head;
}

int main() {
    int arr1[] = {0};
    int arr2[] = {0};

    struct ListNode* l1 = createList(arr1, 1);
    struct ListNode* l2 = createList(arr2, 1);

    struct ListNode* result = addTwoNumbers(l1, l2);

    return 0;
}
