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
    long res = 0;
    const int mod = 1e9 + 7;
    int sum(TreeNode *root, long total)
    {
        if (!root)
            return 0;
        int s1 = sum(root->left, total);
        int s2 = sum(root->right, total);
        int s = s1 + s2 + root->val;
        res = max(res, s * (total - s));
        return s;
    }
    int maxProduct(TreeNode *root)
    {
        //
        int total = sum(root, 0);
        sum(root, total);
        return res % mod;
    }
};