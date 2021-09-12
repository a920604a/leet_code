/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverse(struct TreeNode *root, int *k, int *ret)
{
    if (root == NULL)
        return;
    traverse(root->left, k, ret);
    *k -= 1; //
    if (*k == 0)
    {
        *ret = root->val;
        return;
    }
    traverse(root->right, k, ret);
}
int kthSmallest(struct TreeNode *root, int k)
{
    int count = k;
    int ret = 0;
    traverse(root, &count, &ret);
    return ret;
}