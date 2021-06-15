/*
 * @Author: yuan
 * @Date: 2021-05-01 19:06:36
 * @LastEditTime: 2021-05-01 19:06:36
 * @FilePath: /C_plus/230_KthSmallestElementInaBST.cpp
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
    void traverse(TreeNode *root, vector<int> &ret)
    {
        if (root)
        {
            ret.push_back(root->val);
            if (root->left)
                traverse(root->left, ret);
            if (root->right)
                traverse(root->right, ret);
        }
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> ret;
        traverse(root, ret);
        sort(ret.begin(), ret.end());
        return ret[k - 1];
    }
};