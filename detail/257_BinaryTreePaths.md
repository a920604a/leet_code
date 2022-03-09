---
title: 257. Binary Tree Paths
tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/binary-tree-paths/)

## solution
```c++
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
    vector<string> ret;
    void traverse(TreeNode *root, string path){
        if(!root) return;
        
        
        if(!root->right && !root->left){
            path+=to_string(root->val);
            ret.push_back(path);
            return;
        }
        else path+=to_string(root->val)+"->";
        traverse(root->left,path);
        traverse(root->right,path);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        traverse(root, path);
        return ret;
    }
};
```