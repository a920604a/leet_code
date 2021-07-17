/*
 * @Author: yuan
 * @Date: 2021-07-16 20:50:06
 * @LastEditTime: 2021-07-16 20:50:06
 * @FilePath: /leet_code/C_plus/606*_ConstructStringfromBinaryTree.cpp
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
    string tree2str(TreeNode *root)
    {
        if (!root)
            return "";
        string ret = to_string(root->val);
        if (root->left)
            ret += "(" + tree2str(root->left) + ")";
        else if (root->right)
            ret += "()";
        if (root->right)
            ret += "(" + tree2str(root->right) + ")";
        return ret;
    }
};