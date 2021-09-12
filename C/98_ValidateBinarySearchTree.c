/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValid(struct TreeNode *root, long l, long r)
{

    if (!root)
        return true;
    if (l >= root->val)
        return false;
    if (r <= root->val)
        return false;
    return isValid(root->left, l, root->val) && isValid(root->right, root->val, r);
}
bool isValidBST(struct TreeNode *root)
{
    if (!root)
        return true;
    return isValid(root, LONG_MIN, LONG_MAX);
}