/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countNodes(struct TreeNode *root)
{
    if (!root)
        return 0;
    int count = 0;
    struct TreeNode *left, *right;
    left = right = root;
    int l = 1, r = 1;
    while (left->left)
    {
        left = left->left;
        l++;
    }
    while (right->right)
    {
        right = right->right;
        r++;
    }
    if (l == r)
        return pow(2, l) - 1;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}