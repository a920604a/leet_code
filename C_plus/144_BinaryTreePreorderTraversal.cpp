/*
 * @Author: yuan
 * @Date: 2021-04-27 15:44:33
 * @LastEditTime: 2021-04-27 15:45:02
 * @FilePath: /C_plus/144_BinaryTreeInorderTraversal.cpp
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
    void preorder(TreeNode *root, vector<int> &ret)
    {
        if (root)
        {
            ret.push_back(root->val); //V
            if (root->left)
                preorder(root->left, ret); //L
            if (root->right)
                preorder(root->right, ret); //R
        }
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        preorder(root, ret);
        return ret;
    }
};