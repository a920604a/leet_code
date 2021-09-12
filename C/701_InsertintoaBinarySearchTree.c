/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{

    if (!root)
    {
        struct TreeNode *ret = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        ret->val = val;
        ret->left = NULL;
        ret->right = NULL;
        return ret;
    }
    if (root->val < val)
        root->right = insertIntoBST(root->right, val);
    else if (root->val > val)
        root->left = insertIntoBST(root->left, val);
    return root;
}