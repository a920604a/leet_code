/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode *root)
{
    if (!root)
        return;
    flatten(root->left);
    flatten(root->right);
    struct TreeNode *temp = root->right;
    struct TreeNode *p = root;
    root->right = root->left;
    root->left = NULL;
    while (p->right)
        p = p->right;
    p->right = temp;
}