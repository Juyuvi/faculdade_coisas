/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {

    if( !root ) return root;

    invertTree(root->left);
    invertTree(root->right);


    struct TreeNode * aux;

    aux = root->right;

    root->right = root->left;
    root->left = aux;

    return root;
}