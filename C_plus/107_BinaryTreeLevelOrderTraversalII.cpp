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
    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int> > ret;
        if (!root)
            return ret;
        q.push(root);

        int number_of_node;
        while (!q.empty())
        {
            number_of_node = q.size();
            vector<int> temp;
            while (number_of_node)
            {
                number_of_node--;
                TreeNode *cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            ret.insert(ret.begin(), temp);
        }
        return ret;
    }
};