/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool covers(TreeNode *root, TreeNode *p)
    {
        if (!root)
            return false;
        if (root == p)
            return true;
        return covers(root->left, p) || covers(root->right, p);
    }

    TreeNode *ancestorHelper(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
            return root;

        bool pIsOnLeft = covers(root->left, p);
        bool qIsOnLeft = covers(root->left, q);
        if (pIsOnLeft != qIsOnLeft)
            return root;

        TreeNode *childSide = pIsOnLeft ? root->left : root->right;

        return ancestorHelper(childSide, p, q);
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // option 1
        // check exist in the tree
        // if(!covers(root, p) || !covers(root, q)) return nullptr;

        // return ancestorHelper(root, p, q);

        // option 2

        if (!root || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (right && left)
            return root;
        return left ? left : right;
    }
};