/*
 * @Author: yuan
 * @Date: 2021-07-17 10:19:00
 * @LastEditTime: 2021-07-17 10:19:01
 * @FilePath: /leet_code/C_plus/1022*_SumofRootToLeafBinaryNumbers.cpp
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
    void path(TreeNode *root, vector<int> &cand, int tmp)
    {
        if (!root)
            return;

        tmp *= 2;
        tmp += root->val;

        if (root->left == nullptr && root->right == nullptr)
        {
            cand.push_back(tmp);
        }
        path(root->left, cand, tmp);
        path(root->right, cand, tmp);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        // option 1
        // vector<int> cand;
        // path(root, cand,0);
        // int ans =0 ;
        // for(int n:cand) ans +=n;
        // return ans;

        //option 1.1
        int ans = 0;
        pathSum(root, 0, ans);
        return ans;
    }
    void pathSum(TreeNode *root, int cur, int &ans)
    {
        if (!root)
            return;

        cur = 2 * cur + root->val;
        if (root->left == nullptr && root->right == nullptr)
            ans += cur;

        pathSum(root->left, cur, ans);
        pathSum(root->right, cur, ans);
    }
};