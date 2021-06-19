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
class Solution {
public:
    void swapChild(TreeNode * root){
        
        if (!root) return;
        TreeNode * tempnode = root->left;
        root->left = root->right;
        root->right = tempnode;
        swapChild(root->left);
        swapChild(root->right);
        
        
        
    }
    TreeNode* invertTree(TreeNode* root) {
        
        // option 1
        // return TreeNode* imply can new new tree
        // if(!root) return root;
        // TreeNode * newroot = new TreeNode(root->val);
        // newroot->left = invertTree(root->right);
        // newroot->right = invertTree(root->left);
        // return newroot;
        
        // option 2 
        // in-place , use swap child
        swapChild(root);
        return root;
        
    }
};