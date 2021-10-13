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
    void traverse(TreeNode *root, int target, vector<int> &path, vector<vector<int> > &ret)
    {

        if (!root)
            return;

        path.push_back(root->val);
        target -= root->val;

        if (!root->left && !root->right)
        {
            if (target == 0)
            {
                ret.push_back(path);
            }
            return;
        }

        if (root->left)
        {
            traverse(root->left, target, path, ret);
            path.pop_back();
        }
        if (root->right)
        {
            traverse(root->right, target, path, ret);
            path.pop_back();
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int targetSum)
    {

        vector<vector<int> > ret;
        vector<int> path;
        traverse(root, targetSum, path, ret);
        return ret;
    }
    // option 2 BFS
}
}
;