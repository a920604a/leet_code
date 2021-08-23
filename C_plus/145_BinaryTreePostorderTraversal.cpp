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
    void postorder(TreeNode *root, vector<int> &ret)
    {

        if (root)
        {
            postorder(root->left, ret);  // L
            postorder(root->right, ret); // R
            ret.push_back(root->val);    // V
        }
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        // option 1 recursive O(n) space
        vector<int> ret;
        postorder(root, ret);
        return ret;

        // option 2 non-recursive O(n) space
        // option 3 Morris Traversal O(1) space
        
    }
};