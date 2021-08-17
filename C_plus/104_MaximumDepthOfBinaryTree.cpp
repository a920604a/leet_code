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
    int maxDepth(TreeNode *root)
    {
        // option 1 recursive DFS
        // if(!root) return 0;
        // return 1+ max(maxDepth(root->left), maxDepth(root->right));

        // optnio 2 iterative BFS + queue
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int step = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *p = q.front();
                q.pop();
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            step++;
        }
        return step;
    }
};