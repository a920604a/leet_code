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
    TreeNode *constructFromPrePost(vector<int> &preorder, int lo, int hi, vector<int> &postorder, int l, int r)
    {

        if (lo > hi || l > r)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[lo]);
        if (lo == hi)
            return root;

        int idx = l;
        while (postorder[idx] != preorder[lo + 1])
            idx++;
        int len = idx - l + 1;

        root->left = constructFromPrePost(preorder, lo + 1, lo + len, postorder, l, idx);
        root->right = constructFromPrePost(preorder, lo + len + 1, hi, postorder, idx + 1, r - 1);
        return root;
    }
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        return constructFromPrePost(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};