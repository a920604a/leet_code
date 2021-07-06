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
    void findPaths(TreeNode *root, int targetSum, vector<int> &path, vector<vector<int> > &paths)
    {
        if (!root)
            return;
        path.push_back(root->val);
        if (root->val == targetSum && !root->left && !root->right)
        {
            paths.push_back(path);
        }

        int target = targetSum - root->val;
        findPaths(root->left, target, path, paths);
        findPaths(root->right, target, path, paths);
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