/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *construct(int *nums, int l, int r)
{
    if (l > r)
        return NULL;
    int idx = l, val = nums[l];
    for (int i = l; i <= r; ++i)
    {
        if (val < nums[i])
        {
            val = nums[i];
            idx = i;
        }
    }

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = construct(nums, l, idx - 1);
    root->right = construct(nums, idx + 1, r);
    return root;
}
struct TreeNode *constructMaximumBinaryTree(int *nums, int numsSize)
{
    return construct(nums, 0, numsSize - 1);
}