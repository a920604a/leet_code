---
title: 701. Insert into a Binary Search Tree

tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/insert-into-a-binary-search-tree/)

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 找到插入位置
        if(root==nullptr){
            return new TreeNode(val);
        }
        // 往右子樹尋找
        else if(root->val < val) root->right = insertIntoBST(root->right, val);
        // 往左子樹尋找
        else root->left = insertIntoBST(root->left, val);
        
        return root;
        
    }
};
```
