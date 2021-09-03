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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        // option 1
        //         if(!root1 && !root2) return nullptr;
        //         int val = 0;
        //         if(root1) val+= root1->val;
        //         if(root2) val+= root2->val;
        //         TreeNode *root = new TreeNode(val);

        //         if(root1 && root2 ) root->left = mergeTrees(root1->left, root2->left);
        //         else if(!root1) root->left = mergeTrees(nullptr, root2->left);
        //         else if(!root2) root->left = mergeTrees(root1->left, nullptr);

        //         if(root1 && root2 ) root->right = mergeTrees(root1->right, root2->right);
        //         else if(!root1) root->right = mergeTrees(nullptr, root2->right);
        //         else if(!root2) root->right = mergeTrees(root1->right, nullptr);

        //         return root;

        // option 2
        if (!root1 && !root2)
            return nullptr;
        if (!root2)
            return root1;
        if (!root1)
            return root2;
        TreeNode *root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
};