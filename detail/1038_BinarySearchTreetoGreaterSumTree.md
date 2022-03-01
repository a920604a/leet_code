---
title: 1038. Binary Search Tree to Greater Sum Tree

tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)

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
    void inorder(TreeNode* root, int &val){
        if(!root) return ;
        
        inorder(root->right, val);
        
        val+=root->val;
        root->val = val;
        
        inorder(root->left, val);
        
    }
    TreeNode* bstToGst(TreeNode* root) {
        int val = 0;
        inorder(root, val);
        return root;
        
    }
};

```