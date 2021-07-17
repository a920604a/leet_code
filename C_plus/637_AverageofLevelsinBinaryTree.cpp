/*
 * @Author: yuan
 * @Date: 2021-07-16 21:31:46
 * @LastEditTime: 2021-07-16 21:31:54
 * @FilePath: /leet_code/C_plus/637_AverageofLevelsinBinaryTree.cpp
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
    void levelorder(TreeNode *root, vector<double> &ret)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            double total = 0, cap = size;
            while (size)
            {
                TreeNode *cur = q.front();
                q.pop();
                total += cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                size--;
            }
            ret.push_back(total / cap);
        }
    }
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ret;
        levelorder(root, ret);
        return ret;
    }
};
