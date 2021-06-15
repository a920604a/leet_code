/*
 * @Author: yuan
 * @Date: 2021-05-05 14:40:07
 * @LastEditTime: 2021-05-05 14:40:07
 * @FilePath: /C_plus/1008_ConstructBinarySearchTreefromPreorderTraversal.cpp
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
    TreeNode *bstFromPreorder(vector<int> preorder, int left, int right)
    {
        if (left == right)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[left]);
        int i = left + 1;
        while (i < right && preorder[i] < root->val)
            i++;
        root->left = bstFromPreorder(preorder, left + 1, i);
        root->right = bstFromPreorder(preorder, i, right);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return bstFromPreorder(preorder, 0, preorder.size());
    }
};