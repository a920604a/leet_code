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
    void traverse(TreeNode *root, int *val)
    {
        if (!root)
            return;

        traverse(root->right, val);
        root->val += *val;
        *val = root->val;
        traverse(root->left, val);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        int val = 0;
        traverse(root, &val);
        return root;
    }
};