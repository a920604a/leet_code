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

#### option 2 - dp
```c++
public:
    vector<int> dfs(TreeNode *root){
        if(!root) return vector<int>(2,0);
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        vector<int> ret(2,0);
        // not_do_it vs. do_it
        ret[0] = max(left[0], left[1]) + max(right[0], right[1]);
        ret[1] = left[0]+right[0]+root->val;
        return ret;
        
    }
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
};
```

## analysis