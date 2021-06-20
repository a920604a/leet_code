/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int depth(TreeNode *root, int &ret)
    {
        if (!root)
            return 0;
        int left = depth(root->left, ret);
        int right = depth(root->right, ret);
        ret = max(ret, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ret = 0;
        depth(root, ret);
        return ret;
    }
};