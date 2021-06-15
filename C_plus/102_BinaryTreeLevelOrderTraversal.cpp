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
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > ret;
        queue<TreeNode *> q;
        if (!root)
            return ret;
        q.push(root);
        int number_of_node_level;
        while (!q.empty())
        {
            number_of_node_level = q.size();
            vector<int> tmp;
            while (number_of_node_level)
            {
                TreeNode *cur = q.front();
                q.pop();
                number_of_node_level--;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                tmp.push_back(cur->val);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};