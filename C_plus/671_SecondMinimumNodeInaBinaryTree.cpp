/*
 * @Author: yuan
 * @Date: 2021-07-16 22:02:10
 * @LastEditTime: 2021-07-16 22:02:10
 * @FilePath: /leet_code/C_plus/671_SecondMinimumNodeInaBinaryTree.cpp
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
    void inorder(TreeNode *root, vector<int> &vec)
    {
        if (!root)
            return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    int findSecondMinimumValue(TreeNode *root)
    {
        // 用vector紀錄所有節點
        int ret = -1;
        int mn = INT_MAX;
        vector<int> vec;
        inorder(root, vec);
        sort(vec.begin(), vec.end());
        int n = vec.size();
        if (vec[0] == vec[n - 1] || n == 1)
            return ret;
        mn = vec[0];
        for (int i = 1; i < n; ++i)
        {
            if (vec[i] > mn)
            {
                ret = vec[i];
                break;
            }
        }
        return ret;
    }
};