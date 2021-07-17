/*
 * @Author: yuan
 * @Date: 2021-07-17 10:07:56
 * @LastEditTime: 2021-07-17 10:07:56
 * @FilePath: /leet_code/C_plus/965*_UnivaluedBinaryTree.cpp
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
    void traverse(TreeNode *root, int &ans, bool &ret)
    {
        if (!root)
            return;
        if (root->val != ans)
        {
            ret = false;
            return;
        }
        traverse(root->left, ans, ret);
        traverse(root->right, ans, ret);
    }
    bool helper(TreeNode *node, int &val)
    {
        if (!node)
            return true;
        if (node->val != val)
            return false;
        return helper(node->left, val) && helper(node->right, val);
    }
    bool isUnivalTree(TreeNode *root)
    {
        // option 1
        // int ans = root->val;
        // bool ret = true;
        // traverse(root, ans, ret);
        // return ret;

        // option 1.1
        // return helper(root, root->val);
        //option 1.1.1
        if (!root)
            return true;
        if (root->left && root->left->val != root->val)
            return false;
        if (root->right && root->right->val != root->val)
            return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};