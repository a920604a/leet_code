---
title: 437. Path Sum III
tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/path-sum-iii/)


## solution
```c++
class Solution {
public:
    int traverse(TreeNode * root, int targetSum){
        
        if(!root) return 0;
        
        targetSum -= root->val;
        int ret = 0;
        if(targetSum==0) ret++;
        ret+=traverse(root->left, targetSum)+traverse(root->right, targetSum);
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        if(!root ) return 0;
        // 路徑包含當下的節點
        int ret = traverse(root, targetSum);
        
        ret += pathSum(root->left, targetSum);
        ret += pathSum(root->right, targetSum);
        return ret;
        
    }
};
```