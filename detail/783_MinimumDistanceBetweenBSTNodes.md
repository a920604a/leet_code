---
title: 783. Minimum Distance Between BST Nodes
tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)

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
    void inorder(TreeNode *root, int& prev, int &diff){
        if(!root) return;
        
        inorder(root->left, prev, diff);
        if(prev == -1){
            prev = root->val;
        }
        else{
            diff = min(diff, root->val - prev);
            prev = root->val;
        }
        inorder(root->right, prev, diff);
    }
    int minDiffInBST(TreeNode* root) {
        int diff = INT_MAX, prev = -1;
        inorder(root, prev, diff);
        return diff;
    }
};
```