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
    TreeNode *getParent(TreeNode *root, int val)
    {
        if (root == nullptr)
            return root;
        if (root->val == val)
            return root;

        TreeNode *node = new TreeNode();
        if (val < root->val)
            node = getParent(root->left, val);
        if (val > root->val)
            node = getParent(root->right, val);
        return node;
    }
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // option 1 recursive
        // return getParent(root, val);

        // option 2
        while (root && root->val != val)
        {
            if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};