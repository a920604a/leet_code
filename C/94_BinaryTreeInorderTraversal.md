---
title: 94. Binary Tree Inorder Traversal
tags: 
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/binary-tree-inorder-traversal/)

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
    void inorder(TreeNode* root, vector<int>& ret){
        if(!root) return;
        inorder(root->left, ret);
        ret.push_back(root->val);
        inorder(root->right, ret);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorder(root, ret);
        return ret;
    }
};
```