/*
 * @Author: yuan
 * @Date: 2021-07-16 15:32:44
 * @LastEditTime: 2021-07-16 16:16:42
 * @FilePath: /leet_code/C_plus/257*_BinaryTreePaths.cpp
 */
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
    void path(TreeNode *root, vector<string> & ret, string str){

        
        if(root->left) path(root->left, ret, str+"->" +to_string(root->left->val));
        if(root->right) path(root->right, ret, str+"->"+to_string(root->right->val));
        
        if(root->left==nullptr && root->right==nullptr){
            ret.push_back(str);
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        // option 1 dfs 
        vector<string> ret;
        path(root, ret, to_string(root->val));
        return ret;
    }
};