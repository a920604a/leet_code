/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *build(int *preorder, int pl, int pr, int *inorder, int il, int ir)
{

    if (il > ir || pl > pr)
        return NULL;

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = preorder[pl];
    int idx = -1;
    for (int i = il; i <= ir; ++i)
    {
        if (inorder[i] == preorder[pl])
        {
            idx = i;
            break;
        }
    }
    root->left = build(preorder, pl + 1, pl + idx - il, inorder, il, idx - 1);
    root->right = build(preorder, pl + 1 + idx - il, pr, inorder, idx + 1, ir);
    return root;
}

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    return build(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}