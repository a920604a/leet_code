---
title: 129. Sum Root to Leaf Numbers
tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/sum-root-to-leaf-numbers/)


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
    int ret = 0;
    void traverse(TreeNode * root, int path){
        if(!root) return;
        path*=10;
        path+=root->val;
        // 提前終止
        if(!root->left && !root->right){
            // cout<<path<<endl;
            ret+=path;
            return;
        }
        
        traverse(root->left, path);
        traverse(root->right, path);
        
    }
    int sumNumbers(TreeNode* root) {
        
        traverse(root, 0);
        return ret;
    }
};
```
