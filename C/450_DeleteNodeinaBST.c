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

    if (root == NULL)
        return NULL;
    if (root->val == key)
    {
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;

        struct TreeNode *p = findNext(root->right);
        root->val = p->val;
        root->right = deleteNode(root->right, p->val);
    }
    else if (root->val < key)
        root->right = deleteNode(root->right, key);
    else if (root->val > key)
        root->left = deleteNode(root->left, key);
    return root;
}