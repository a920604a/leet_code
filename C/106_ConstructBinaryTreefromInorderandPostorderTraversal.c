/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *build(int *inorder, int il, int ir, int *postorder, int pl, int pr)
{
    if (pl > pr || il > ir)
        return NULL;
    int idx = -1, val = -1;
    for (int i = il; i <= ir; ++i)
    {
        if (inorder[i] == postorder[pr])
        {
            idx = i;
            break;
        }
    }

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = postorder[pr];
    root->left = build(inorder, il, idx - 1, postorder, pl, pl + idx - il - 1);
    root->right = build(inorder, idx + 1, ir, postorder, pl + idx - il, pr - 1);
    return root;
}
struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize)
{

    return build(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}