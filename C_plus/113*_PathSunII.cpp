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
    void findPaths(TreeNode *root, int target, vector<int> &path, vector<vector<int> > &paths)
    {
        if (!root)
            return;
        target -= root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && target == 0)
        {
            ret.push_back(path);
        }

        traverse(root->left, target, path, ret);
        traverse(root->right, target, path, ret);
        path.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int targetSum)
    {
        // option 1 DFS
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, targetSum, path, paths);
        for (int p : path)
            cout << p << " ";
        return paths;

        // option 2 BFS
    }
};