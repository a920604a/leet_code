/*
 * @Author: yuan
 * @Date: 2021-07-16 21:20:46
 * @LastEditTime: 2021-07-16 21:23:03
 * @FilePath: /leet_code/C_plus/617*_MergeTwoBinaryTrees.cpp
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return nullptr;
        int val = 0;
        if (root1)
            val += root1->val;
        if (root2)
            val += root2->val;
        TreeNode *ret = new TreeNode(val);
        if (root1 && root2)
            ret->left = mergeTrees(root1->left, root2->left);
        else if (!root1)
            ret->left = mergeTrees(nullptr, root2->left);
        else if (!root2)
            ret->left = mergeTrees(nullptr, root1->left);

        if (root1 && root2)
            ret->right = mergeTrees(root1->right, root2->right);
        else if (!root1)
            ret->right = mergeTrees(nullptr, root2->right);
        else if (!root2)
            ret->right = mergeTrees(nullptr, root1->right);

        return ret;
    }
};