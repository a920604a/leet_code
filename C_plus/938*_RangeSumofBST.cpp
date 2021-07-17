/*
 * @Author: yuan
 * @Date: 2021-07-17 09:59:47
 * @LastEditTime: 2021-07-17 09:59:47
 * @FilePath: /leet_code/C_plus/938*_RangeSumofBST.cpp
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
    void inorder(TreeNode *root, int &ans, int &low, int &high)
    {
        if (!root)
            return;

        inorder(root->left, ans, low, high);
        if (root->val >= low && root->val <= high)
            ans += root->val;

        inorder(root->right, ans, low, high);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        // option 1 easy to understand
        // int ans = 0 ;
        // inorder(root, ans, low, high);
        // return ans;

        // option 2 make use of property of BST
        if (!root)
            return 0;
        if (root->val < low)
            return rangeSumBST(root->right, low, high);
        else if (root->val > high)
            return rangeSumBST(root->left, low, high);
        return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high) + root->val;
    }
};