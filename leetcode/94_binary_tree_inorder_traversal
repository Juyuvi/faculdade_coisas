/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int * helper(struct TreeNode* root, int* returnSize, int ** array);


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* array = ( int *) malloc(sizeof(int));
    helper(root, returnSize, &array);
    return array;
}

int * helper(struct TreeNode* root, int* returnSize, int ** array){

    printf("1\n");
        
    if(root){
        if (root->left){
            helper(root->left, returnSize, array);
        }

            printf("retSize: %d\n", (*returnSize));
            *array = realloc(*array, (int) (++(*returnSize) * (sizeof(int))));
            *(*array + *returnSize - 1) = root->val;
            printf("%d ", root->val);
        


        if (root->right){
            helper(root->right, returnSize, array);
        }
    }

    return *array;
}