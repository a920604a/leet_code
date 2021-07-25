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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int il, int ir, int pl, int pr)
    {
        if (il > ir || pl > pr)
            return nullptr;
        // preorder traverse
        // 從postorder最後一個元素找出root
        TreeNode *root = new TreeNode(postorder[pr]);
        // 從 inorder 找尋根節點，並切分出左右子樹的數組
        int index = 0;
        for (int i = il; i <= ir; ++i)
        {
            if (inorder[i] == postorder[pr])
            {
                index = i;
                break;
            }
        }

        root->left = buildTree(inorder, postorder, il, index - 1, pl, pl + index - il - 1);
        root->right = buildTree(inorder, postorder, index + 1, ir, pl + index - il, pr - 1);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};