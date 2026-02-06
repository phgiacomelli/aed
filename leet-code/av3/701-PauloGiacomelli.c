//M2 - Paulo Henrique Anesi Giacomelli
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

 struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        struct TreeNode* newNode = malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return root;
    }

    if (val > root->val) root->right = insertIntoBST(root->right, val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);

    return root;
}

int main() {

    struct TreeNode* root = NULL;
    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 4);
    root = insertIntoBST(root, 6);
    root = insertIntoBST(root, 5);
    
    return 0;
}