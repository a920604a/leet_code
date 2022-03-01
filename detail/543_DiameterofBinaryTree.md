---
title: 543. Diameter of Binary Tree
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/diameter-of-binary-tree/)


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
    int maxDepth(TreeNode *root){
        if(!root) return 0;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // dfs 
        // 最大直徑不一定會經過根節點
        if(!root) return 0;
        int diameter = maxDepth(root->left) + maxDepth(root->right);
        diameter = max(diameter, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
        return diameter;
        
    }
};
```


```c++
class Solution {
public:
    int depth(TreeNode *root, int &ret){
        if(!root) return 0;
        int l = depth(root->left, ret);
        int r = depth(root->right, ret);
        ret = max(r+l, ret);
        return 1+max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ret = 0;
        depth(root, ret);
        return ret;
        
    }
};
```
## analysis