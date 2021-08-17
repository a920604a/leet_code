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
    bool isCousins(TreeNode *root, int x, int y)
    {

        // level order 因為是cousin 必定在同一層
        queue<TreeNode *> q;
        q.push(root);
        bool stepX = false, stepY = false;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *p = q.front();
                q.pop();
                if (p->val == x)
                    stepX = true;
                if (p->val == y)
                    stepY = true;
                if (p->left && p->right)
                {
                    // 檢查是否為兄弟
                    int left = p->left->val, right = p->right->val;
                    if ((left == x) && (right == y) || (left == y) && (right == x))
                        return false;
                }

                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            if (stepX && stepY)
                return true;
            if (stepX || stepY)
                return false;
        }
        return false;
    }
};