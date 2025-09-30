#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head);

struct ListNode* insert(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    struct ListNode* head = insert(1);
    head->next = insert(2);
    head->next->next = insert(3);
    head->next->next->next = insert(4);
    head->next->next->next->next = insert(5);
    head->next->next->next->next->next = insert(6);

    struct ListNode* mid = middleNode(head);

    printf("Middle: ");
    while (mid != NULL) {
        printf("%d ", mid->val);
        mid = mid->next;
    }
    printf("\n");

    return 0;
}

struct ListNode* middleNode(struct ListNode* head) {
    int quant = 0;
    for (struct ListNode* i = head; i!=NULL; i=i->next)
        quant++;

    struct ListNode *mid = NULL;
    mid = head;
    for (int j = 0; j < quant/2; j++)
        mid=mid->next;
    
    return mid;    
}