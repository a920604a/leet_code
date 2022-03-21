---
title: 129. Sum Root to Leaf Numbers
tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/sum-root-to-leaf-numbers/)


## solution
#### option 1 - dfs
```c++
class Solution {
public:
    int ret = 0;
    void traverse(TreeNode * root, int path){
        if(!root) return;
        path = 10*path + root->val;
        // 提前終止
        if(!root->left && !root->right){
            ret+=path;
            return;
        }
        traverse(root->left, path);
        traverse(root->right, path);
        
    }
    int sumNumbers(TreeNode* root) {
        
        traverse(root, 0);
        return ret;
    }
};
```

#### option 2 - bfs
```c++
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        //  bfs
        if(!root) return 0;
        queue<pair<TreeNode *,int> >  q;
        q.push({root, root->val});
        int depth = 0, ret = 0;
        while(!q.empty()){
            int size = q.size();
            for(int _ = 0;_<size ; ++_){
                auto [p,val] = q.front(); q.pop();
                
                if(!p->left && !p->right) ret+=val;
                if(p->left) q.push({p->left, 10*val+p->left->val});
                if(p->right) q.push({p->right, 10*val+p->right->val});
                
            }
        }
        return ret;
        
    }
};
```
