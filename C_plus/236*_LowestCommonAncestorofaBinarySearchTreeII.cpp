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
        if(pIsOnLeft != qIsOnLeft) return root;
        TreeNode *childSide;
        if(pIsOnLeft==false && qIsOnLeft == false) childSide = root->right;
        if(pIsOnLeft==true && qIsOnLeft==true ) childSide = root->left;
        
        return ancestor(childSide, p,q);
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // option 1
        // check exist in the tree
        // if(!covers(root, p) || !covers(root, q)) return nullptr;

        // return ancestorHelper(root, p, q);

        // option 2 recursive postorder
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // 情況一， p q 都是在以root 為根的樹中
        if (left != nullptr && right != nullptr)
            return root;
        // 情況二，p q都不在以root為根的樹中
        if (left == nullptr && right == nullptr)
            return nullptr;
        // 情況三，如果p q只有其中一點 存在於root中，返回該點
        return left == nullptr ? right : left;
    }
};