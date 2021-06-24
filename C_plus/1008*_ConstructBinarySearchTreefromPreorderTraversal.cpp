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
    TreeNode *bstFromPreorder(vector<int> &preorder, int l, int r)
    {
        if (l == r)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[l]); // V
        int i = l + 1;
        while (i < r && preorder[i] < root->val)
            i++;
        root->left = bstFromPreorder(preorder, l + 1, i); // L
        root->right = bstFromPreorder(preorder, i, r);    // R
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {

        return bstFromPreorder(preorder, 0, preorder.size());
    }
};