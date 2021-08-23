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
    vector<vector<int> > pathSum;
    void traverse(TreeNode *root, vector<int> &path)
    {
        if (!root)
            return;

        path.push_back(root->val);
        // this is leaf
        if (!root->left && !root->right)
        {
            pathSum.push_back(path);
            path.pop_back();
            return;
        }

        traverse(root->left, path);
        traverse(root->right, path);
        path.pop_back();
    }
    int sumNumbers(TreeNode *root)
    {
        vector<int> path;
        traverse(root, path);

        int ret = 0;
        for (auto path : pathSum)
        {
            int sum = 0;
            for (int p : path)
                sum = 10 * sum + p;

            ret += sum;
        }
        return ret;
    }
};