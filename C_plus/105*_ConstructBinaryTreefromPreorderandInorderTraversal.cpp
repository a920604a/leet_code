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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir)
    {
        if (pl > pr || il > ir)
            return nullptr;
        int i = 0;
        for (i = il; i <= ir; i++)
        {
            if (inorder[i] == preorder[pl])
                break;
        }
        TreeNode *root = new TreeNode(preorder[pl]);

        root->left = buildTree(preorder, inorder, pl + 1, pr + i - il, il, i - 1);
        root->right = buildTree(preorder, inorder, pl + i - il + 1, pr, i + 1, ir);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // inorder  LVR preorder VLR
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};