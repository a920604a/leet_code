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
    void preorder(TreeNode *root, vector<int> &ret)
    {
        if (!root)
            return;
        ret.push_back(root->val);   // V
        preorder(root->left, ret);  // L
        preorder(root->right, ret); // R
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        // preorder VLR
        vector<int> ret;
        preorder(root, ret);
        return ret;
    }
};