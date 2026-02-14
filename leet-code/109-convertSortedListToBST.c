#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// struct TreeNode* sortedListToBST(struct ListNode* head) {
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL) return NULL;
    
    if (head->next == NULL){
        TreeNode *root = malloc(sizeof(TreeNode));
        root->val = head->val;
        root->left = root->right = NULL;
        return root;
    }
    
    
    // find mid with slow and fast algorithm
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev_slow = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    TreeNode* root = malloc(sizeof(TreeNode));
    root->val = slow->val;
    prev_slow->next = NULL;

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);

    return root;
}

//-10,-3,0,5,9

int main() {
    ListNode a;
    a.val = -10;
    ListNode b;
    b.val = -3;
    ListNode c;
    c.val = 0;
    ListNode d;
    d.val = 5;
    ListNode e;
    e.val = 9;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    TreeNode*root =  sortedListToBST(&a);

    return 0;
}