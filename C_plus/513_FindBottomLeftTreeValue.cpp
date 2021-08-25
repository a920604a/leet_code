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
    int findBottomLeftValue(TreeNode *root)
    {
        // level order traverse
        queue<TreeNode *> q;
        q.push(root);
        int ret = 0;
        while (!q.empty())
        {
            int size = q.size();
            ret = q.front()->val;
            for (int _ = 0; _ < size; _++)
            {
                TreeNode *p = q.front();
                q.pop();

                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
        }
        return ret;
    }
};