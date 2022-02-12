/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *construct(int *preorder, int pl, int pr, int *inorder, int il, int ir)
{
    if (pl > pr || il > ir)
        return NULL;

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[pl];
    int idx = -1;
    for (int i = il; i <= ir; ++i)
    {
        if (inorder[i] == root->val)
        {
            idx = i;
            break;
        }
    }

    root->left = construct(preorder, pl + 1, pl + idx - il, inorder, il, idx - 1);
    root->right = construct(preorder, pl + idx - il + 1, pr, inorder, idx + 1, ir);
    return root;
}
struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    return construct(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}