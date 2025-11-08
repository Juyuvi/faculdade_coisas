/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int depth, dir, esq;
    dir = 0;
    esq = 0;
    depth = 0;

    
    if(root != NULL){
        depth++;
            
        if (root->left){
            esq = maxDepth(root->left);
        }

        if (root->right){
            dir = maxDepth(root->right);
        }
        printf("depth: %d\n", depth);
        if (dir > esq)
        
            return dir + depth;
        return esq + depth;
    }
    return 0;

    
}