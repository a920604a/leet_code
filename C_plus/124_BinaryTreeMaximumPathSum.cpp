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
    int maxPathSum(TreeNode *root)
    {
        int ret = INT_MIN;
        if (!root)
            return 0;
        maxPath(root, ret);
        return ret;
    }

    int maxPath(TreeNode *root, int &ret)
    {
        if (!root)
            return 0;
        int left = max(0, maxPath(root->left, ret));
        int right = max(0, maxPath(root->right, ret));
        ret = max(ret, left + right + root->val);
        return max(left, right) + root->val;
    }
};