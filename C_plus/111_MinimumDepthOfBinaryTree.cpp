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
    int minDepth(TreeNode *root)
    {
        // option 1 recursive  DFS O(logn) space
        // if(!root) return 0;
        // if(!root->left) return 1+minDepth(root->right);
        // if(!root->right) return 1+minDepth(root->left);
        // return 1+min(minDepth(root->left), minDepth(root->right));

        // option 2 BFS O(N) space
        if (root == nullptr)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 1;
        while (!q.empty())
        {
            int size = q.size();
            // 逐層探索
            for (int i = 0; i < size; ++i)
            {
                TreeNode *cur = q.front();
                q.pop();
                // 判斷是否到達終點
                if (cur->left == nullptr && cur->right == nullptr)
                {
                    return depth;
                }
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            // 完成一層探索，深度加一
            depth++;
        }
        return depth;
    }
};