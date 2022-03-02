---
title: 124. Binary Tree Maximum Path Sum
tags:  
    - backtracking
    - bfs
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

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
    int maxPath(TreeNode *root, int &ret ){
        if(!root) return 0;
        
        int left =max(maxPath(root->left, ret),0);
        int right =max(maxPath(root->right, ret),0);
        // 由當前節點當作起點的最大路徑
        ret = max(ret, root->val + left+right);
        // 左邊到右邊包含當前節點的最大路境
        return max(left, right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ret = INT_MIN;
        maxPath(root, ret);
        return ret;
    }
};
```