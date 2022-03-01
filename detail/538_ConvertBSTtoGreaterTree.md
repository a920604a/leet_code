---
title: 538. Convert BST to Greater Tree

tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/convert-bst-to-greater-tree/)

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
    TreeNode* convertBST(TreeNode* root) {
        int val = 0;
        inorder(root, val);
        return root;
    }
};
```