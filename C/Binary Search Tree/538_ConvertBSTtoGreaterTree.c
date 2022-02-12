/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverse(struct TreeNode *root, int *sum)
{
    if (!root)
        return NULL;

    traverse(root->right, sum);
    (*sum) += root->val;
    root->val = *sum;
    traverse(root->left, sum);
}
struct TreeNode *convertBST(struct TreeNode *root)
{
    int sum = 0;
    traverse(root, &sum);
    return root;
}