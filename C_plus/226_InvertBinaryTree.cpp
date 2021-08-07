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
    void swapChild(TreeNode *node)
    {

        // base case
        if (node == nullptr)
            return;

        // option 1 preorder
        // 當前這node要做的事情
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;

        swapChild(node->left);
        swapChild(node->right);

        // option 2 postorder faster than preorder

        // swapChild(node->left);
        // swapChild(node->right);
        // // 當前這node要做的事情
        // swap(node->left, node->right);

        // inorder 也是可以處理這問題，但不直觀。需拜訪兩次左子樹

        // swapChild(node->left);
        // TreeNode *temp = node->left;
        // node->left = node->right;
        // node->right = temp;
        // swapChild(node->left);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        // option 1 construct new tree
        if (!root)
            return root;
        TreeNode *newroot = new TreeNode(root->val);
        newroot->left = invertTree(root->right);
        newroot->right = invertTree(root->left);
        return newroot;

        // option 2 recursive
        // DFS postorder in-place
        // swapChild(root);
        // return root;
    }
};
