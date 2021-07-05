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
        if (root == nullptr)
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
        // take advantage of the proerty binary search tree
        // option 1 recursive
        // left->val < root->val < right->val
        // if ((root -> val > p -> val) && (root -> val > q -> val)) {
        //     return lowestCommonAncestor(root -> left, p, q);
        // }
        // else if((root -> val < p -> val) && (root -> val < q -> val)){
        //     return lowestCommonAncestor(root -> right, p, q);
        // }
        // return root;

        // option 2 iterative
        // while (true) {
        //     if (p -> val < root -> val && q -> val <root -> val) {
        //         root = root -> left;
        //     } else if (p -> val > root -> val && q -> val > root -> val) {
        //         root = root -> right;
        //     } else {
        //         break;
        //     }
        // }
        // return root;

        // option 3 considering to binary tree
        // if(!covers(root, p) || !covers(root, q)) return nullptr;
        return ancestorHelper(root, p, q);
    }
};