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
    TreeNode *buildTree(vector<int> &preorder, int lo, int hi, vector<int> &inorder, int l, int r)
    {

        if (lo > hi || l > r)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[lo]);

        int idx = -1, val = preorder[lo];
        for (int i = l; i <= r; ++i)
        {
            if (val == inorder[i])
            {
                idx = i;
                break;
            }
        }

        root->left = buildTree(preorder, lo + 1, lo + idx - l, inorder, l, idx - 1);
        root->right = buildTree(preorder, lo + idx - l + 1, hi, inorder, idx + 1, r);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};