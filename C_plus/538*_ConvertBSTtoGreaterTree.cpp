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
        // reverse-inorder //RVL
        if (root == nullptr)
            return;
        // R
        traverse(root->right);
        // V
        sum += root->val;
        root->val = sum;
        // L
        traverse(root->left);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        // option 1
        // traverse(root);
        // return root;

        // option 2 iterative + stack support
        int sum = 0;
        stack<TreeNode *> sta;
        TreeNode *p = root;
        while (p || !sta.empty())
        {
            // R
            while (p)
            {
                sta.push(p);
                p = p->right;
            }
            p = sta.top();
            sta.pop();

            // V
            sum += p->val;
            p->val = sum;

            // L
            p = p->left;
        }
        return root;
    }
};