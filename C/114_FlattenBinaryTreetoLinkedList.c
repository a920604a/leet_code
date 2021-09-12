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
    struct TreeNde *temp = root->right;
    root->right = root->left;
    root->left = NULL;
    struct TreeNode *p = root;
    while (p->right)
        p = p->right;
    p->right = temp;
}