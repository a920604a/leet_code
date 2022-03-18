---
title: 112. Path Sum
tags:  
    - backtracking
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/path-sum/)


## solution

#### option 1 - dfs
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

#### option 2 - bfs

```c++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        queue<pair<TreeNode*,int>> q;
        q.push({root, root->val});
        while(!q.empty()){
            auto [p, val] = q.front();
            q.pop();
            if(!p->left && !p->right && val == targetSum) return true;
            if(p->left) q.push({p->left, p->left->val+val});
            if(p->right) q.push({p->right, p->right->val + val});
        }
        return false;
    }
};
```