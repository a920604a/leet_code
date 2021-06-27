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
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        TreeNode *pre = new TreeNode(-1), *ret = pre;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
            pre->right = node;
            pre->left = nullptr;
            if (node->right)
                s.push(node->right);
            if (node->left)
                s.push(node->left);
            pre = node;
        }
        // root = ret->right;
    }
};