/*
 * @Author: yuan
 * @Date: 2021-05-05 13:52:52
 * @LastEditTime: 2021-05-05 13:52:52
 * @FilePath: /C_plus/993_CousinsinBinaryTree.cpp
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
    void dfs(TreeNode *root, map<int, pair<TreeNode *, int> > &m, TreeNode *parent, int depth)
    {
        if (!root)
            return;
        m[root->val] = make_pair(parent, depth);
        dfs(root->left, m, root, depth + 1);
        dfs(root->right, m, root, depth + 1);
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        map<int, pair<TreeNode *, int> > m;
        dfs(root, m, nullptr, 0);
        return (m[x].first != m[y].first) && (m[x].second == m[y].second);
    }
};