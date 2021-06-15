/*
 * @Author: yuan
 * @Date: 2021-05-01 18:45:08
 * @LastEditTime: 2021-05-01 18:45:08
 * @FilePath: /C_plus/236_InvertBinaryTree.cpp
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
    void swapChild(TreeNode *root)
    {
        if (!root)
            return;
        else if (root)
        {
            TreeNode *node = root->right;
            root->right = root->left;
            root->left = node;
            swapChild(root->left);
            swapChild(root->right);
        }
    }
    TreeNode *invertTree(TreeNode *root)
    {
        swapChild(root);
        return root;
    }
};