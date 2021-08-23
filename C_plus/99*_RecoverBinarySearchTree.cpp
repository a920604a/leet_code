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
    
    void traverse(TreeNode *root, vector<TreeNode*>& list, vector<int>& vals) {
        if(!root) return ;
        
        traverse(root->left, list, vals);
        list.push_back(root);
        vals.push_back(root->val);
        traverse(root->right, list, vals);
        
    }
    void recoverTree(TreeNode* root) {
        // option 1 O(n) space
        vector<TreeNode*> list;
        vector<int> vals;
        traverse(root, list, vals);
        sort(vals.begin(), vals.end());      
        
        for(int i=0;i<list.size() ;++i){
            list[i]->val = vals[i];
        }
        
        // option 2 morris traverse
            
        
    }
};