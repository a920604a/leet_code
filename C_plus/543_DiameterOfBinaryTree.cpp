/*
 * @Author: yuan
 * @Date: 2021-05-04 14:33:55
 * @LastEditTime: 2021-05-04 14:33:55
 * @FilePath: /C_plus/543_DiameterOfBinaryTree.cpp
 */
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
    int depth(TreeNode *root, int &d)
    {
        if (!root)
            return 0;
        int l = depth(root->left, d);
        int r = depth(root->right, d);
        d = max(d, l + r);
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ret = 0;
        depth(root, ret);
        return ret;
    }
};