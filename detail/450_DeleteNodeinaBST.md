---
title: 450. Delete Node in a BST

tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/delete-node-in-a-bst/)

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
    TreeNode * findNext(TreeNode *root){
        while(root->left) root=root->left;
        return root;
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        if(key == root->val){
            
            // 找繼承者
            if(!root->right && !root->left) return nullptr;
            else if(!root->right) return root->left;
            else if(!root->left) return root->right;
            else{
                TreeNode * next = findNext(root->right);
                root->val = next->val;
                root->right = deleteNode(root->right, root->val);
            }
            
        }
        // 往左子樹尋找
        else if(key < root->val) root->left = deleteNode(root->left, key);
        // 往右子樹尋找
        else root->right = deleteNode(root->right, key);
        return root;
        
    }
};
```