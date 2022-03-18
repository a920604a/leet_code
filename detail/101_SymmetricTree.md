---
title: 101. Symmetric Tree
tags:  
    - bfs
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/symmetric-tree/)

## solution 
#### option 1 - dfs
```c++
class Solution {
public:
    bool sym(TreeNode *l, TreeNode *r){
        if(!l && !r) return true;
        if(!l || !r) return false;
        if(l->val != r->val) return false;
        return sym(l->left, r->right) && sym(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return sym(root->left, root->right);
    }
};
```

#### option 2 - bfs 