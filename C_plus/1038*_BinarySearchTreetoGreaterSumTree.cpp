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
private:
    int sum = 0;

public:
    void traverse(TreeNode *root)
    {
        // base case
        if (!root)
            return;
        // R
        traverse(root->right);
        // V
        sum += root->val;
        root->val = sum;
        // L
        traverse(root->left);
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        // option 1
        // traverse(root);
        // return root;

        // option 2 iterative + stack support;
        int sum = 0;
        stack<TreeNode *> sta;
        TreeNode *q = root;
        while (q || !sta.empty())
        {
            // R
            while (q)
            {
                sta.push(q);
                q = q->right;
            }

            q = sta.top();
            sta.pop();

            // V
            sum += q->val;
            q->val = sum;

            // L
            q = q->left;
        }
        return root;
    }
};