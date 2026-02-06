/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int height(struct TreeNode* root){
    int iEsq, iDir;

    if (root == NULL)
        return 0;

    iEsq = height(root->left);
    iDir = height(root->right);

    if (iEsq > iDir)
        return iEsq + 1;
    else
        return iDir + 1;
}


bool isBalanced(struct TreeNode* root) {

    if (root == NULL)
        return 0;

    int res = height(root->left) - height(root->right);

    if (res != 1 || res != -1 || res != 0)
        return false;
    return true;
    
}
