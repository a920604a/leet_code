/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *findNext(struct TreeNode *root)
{
    while (root->left)
        root = root->left;
    return root;
}
struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
    if (!root)
        return NULL;
    if (key == root->val)
    {
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;
        struct TreeNode *temp = findNext(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, root->val);
    }
    else if (key < root->val)
        root->left = deleteNode(root->left, key);
    else
        root->right = deleteNode(root->right, key);
    return root;
}