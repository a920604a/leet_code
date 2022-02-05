/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *construct(int *inorder, int il, int ir, int *postorder, int pl, int pr)
{

    if (il > ir || pl > pr)
        return NULL;

    int idx = -1;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = postorder[pr];
    for (int i = il; i <= ir; ++i)
    {
        if (root->val == inorder[i])
        {
            idx = i;
            break;
        }
    }
    root->left = construct(inorder, il, idx - 1, postorder, pl, pl + idx - il - 1);
    root->right = construct(inorder, idx + 1, ir, postorder, pl + idx - il, pr - 1);
    return root;
}
struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize)
{
    return construct(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}
