#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


struct TreeNode* gerarArvore();
struct TreeNode* insertIntoBST(struct TreeNode* root, int val);

  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };


  int main(){
    struct TreeNode* root = gerarArvore();
    insertIntoBST(root, 5);
  }

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {


    if (root == NULL){
        struct TreeNode* newNode;
            newNode = (struct TreeNode* ) malloc(sizeof(struct TreeNode));
            newNode->val = val;
            newNode->right = NULL;
            newNode->left = NULL;

            return newNode;
    }
    if (val > root->val){
        if (root->right == NULL){
            struct TreeNode* newNode;
            newNode = (struct TreeNode* ) malloc(sizeof(struct TreeNode));
            newNode->val = val;
            newNode->right = NULL;
            newNode->left = NULL;
            printf("\nDir Val: %d", newNode->val);
            root->right = newNode;
            return root;
        }
        insertIntoBST(root->right, val);
    }

    if (val < root->val){
        if (root->left == NULL){

            struct TreeNode* newNode;
           newNode = (struct TreeNode* ) malloc(sizeof(struct TreeNode));
           newNode->val = val;
           newNode->right = NULL;
           newNode->left = NULL;


            printf("\nEsq Val: %d", newNode->val);
            root->left = newNode;
            return root;
        }

        insertIntoBST(root->left, val);
    }

    return root;
}

struct TreeNode* gerarArvore() {
    struct TreeNode *n1 = malloc(sizeof(struct TreeNode));
    struct TreeNode *n2 = malloc(sizeof(struct TreeNode));
    struct TreeNode *n3 = malloc(sizeof(struct TreeNode));
    struct TreeNode *n4 = malloc(sizeof(struct TreeNode));
    struct TreeNode *n7 = malloc(sizeof(struct TreeNode));

    n4->val = 4; n4->left = n2; n4->right = n7;
    n2->val = 2; n2->left = n1; n2->right = n3;
    n7->val = 7; n7->left = NULL; n7->right = NULL;
    n1->val = 1; n1->left = NULL; n1->right = NULL;
    n3->val = 3; n3->left = NULL; n3->right = NULL;

    return n4;
}