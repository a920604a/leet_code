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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        // level order traverse
        if (!root)
            return {};
        vector<vector<int> > ret;
        int flag = 1; // 1 left to right
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *p = q.front();
                q.pop();
                if (flag == 1)
                {
                    tmp.push_back(p->val);
                }
                else
                {
                    tmp.insert(tmp.begin(), p->val);
                }

                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            ret.push_back(tmp);
            flag *= -1;
        }
        return ret;
    }
};