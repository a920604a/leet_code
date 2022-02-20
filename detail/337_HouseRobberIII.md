---
title: 337. House Robber III
tags:  
    - dp
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/house-robber-iii/)

## solution
- dfs - time out

```c++
class Solution {
public:
    int robber(TreeNode* root){
        if(!root) return 0;
        int do_it = root->val, not_do_it=0;
        if(root->left) do_it+=robber(root->left->left)+robber(root->left->right);
        if(root->right) do_it+=robber(root->right->left)+robber(root->right->right);
        not_do_it+=robber(root->left)+robber(root->right);
        return max(do_it,not_do_it);
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        return robber(root);
    }
};
```


#### option 1 - memo pattern
memo 紀錄拜訪過的，避免重複拜訪節點

```c++
class Solution {
public:
    unordered_map<TreeNode*, int> memo;
    int robber(TreeNode* root){
        if(!root) return 0;
        int do_it = root->val, not_do_it=0;
        
        if(memo.find(root)!=memo.end()) return memo[root];
        
        if(root->left) do_it+=robber(root->left->left)+robber(root->left->right);
        if(root->right) do_it+=robber(root->right->left)+robber(root->right->right);
        not_do_it+=robber(root->left)+robber(root->right);
        
        memo[root] = max(do_it,not_do_it);
        return memo[root];
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        return robber(root);
    }
};
```

#### option 2

## analysis