#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int main() {
    struct TreeNode val1;
    val1.val = 1;
    val1.left = NULL;
    val1.right = NULL;

    struct TreeNode val2;
    val1.val = 3;
    val1.left = NULL;
    val1.right = NULL;

    struct TreeNode val3;
    val1.val = 6;
    val1.left = &val1;
    val1.right = &val2;

    struct TreeNode* val4;
    val4 = &val3;
    struct TreeNode* val5;
    val5 = &val1;
    // val1.val = 9;
    // val1.left = NULL;
    // val1.right = NULL;

    struct TreeNode* val6;
    val6 = val4->left;

    if ( val6->left != NULL)
    {
        printf("%d\n", val5->val);
    }
    
    return 0;
}

struct TreeNode* invertTree(struct TreeNode* root) {

    //  if(root->left != NULL && root->right != NULL){
    //     struct TreeNode* cp = NULL;
    //     cp = (struct TreeNode*)malloc(sizeof(struct TreeNode*)); 
    //     cp = root->left;
    //     root->left = root->right;
    //     root->right = cp;
    //     invertTree(root->left);
    //     invertTree(root->right);
    // }




    // return root;
    

    
}