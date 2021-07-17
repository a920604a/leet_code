/*
 * @Author: yuan
 * @Date: 2021-07-16 16:27:03
 * @LastEditTime: 2021-07-16 16:27:03
 * @FilePath: /leet_code/C_plus/530_MinimumAbsoluteDifferenceinBST.cpp
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
    void preorder(TreeNode *root, vector<int> &vec)
    {
        if (root == nullptr)
            return;
        preorder(root->left, vec);
        vec.push_back(root->val);
        preorder(root->right, vec);
    }
    int getMinimumDifference(TreeNode *root)
    {
        // option 1 用dfs + preorder 紀錄節點

        vector<int> vec;
        int ret = 100001;
        preorder(root, vec);
        for (int i = 1; i < vec.size(); ++i)
        {
            int diff = abs(vec[i] - vec[i - 1]);
            ret = min(diff, ret);
        }
        return ret;
    }
};