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
    bool symmteric(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        else if (!left || !right)
            return false;
        if (left->val == right->val)
        {
            return symmteric(left->right, right->left) && symmteric(right->right, left->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode *root)
    {
        return symmteric(root->left, root->right);
    }
};