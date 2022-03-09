---
title: 110. Balanced Binary Tree
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/balanced-binary-tree/)

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
    int Depth(TreeNode *root){
        if(!root) return 0;
        return 1+max( Depth(root->left), Depth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        // determine the height of the children
        int left = Depth(root->left);
        int right = Depth(root->right);
        if(abs(right-left)>1) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
};

```