---
title: 112. Path Sum
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/path-sum/)


## solution
```c++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // dfs
        // 終止條件
        if(!root ) return false;
        targetSum-=root->val;
        // 拜訪到葉子了
        if(!root->left && !root->right && targetSum == 0) return true;
        return hasPathSum(root->left, targetSum ) || hasPathSum(root->right, targetSum);
        
        
        
    }
};
```