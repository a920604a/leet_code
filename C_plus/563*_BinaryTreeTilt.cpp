/*
 * @Author: yuan
 * @Date: 2021-07-16 17:26:22
 * @LastEditTime: 2021-07-16 17:26:22
 * @FilePath: /leet_code/C_plus/563*_BinaryTreeTilt.cpp
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
    int Tilt(TreeNode *root, int &sum)
    {
        if (!root)
            return 0;

        int leftSum = Tilt(root->left, sum);
        int rightSum = Tilt(root->right, sum);
        sum += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
    int findTilt(TreeNode *root)
    {
        // postorder
        if (!root)
            return 0;
        int ret = 0;
        Tilt(root, ret);
        return ret;
    }
};