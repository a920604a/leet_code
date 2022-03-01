---
title: 559. Maximum Depth of N-ary Tree
tags:  
    - backtracking
    - bfs
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/)

## solution

#### dfs
```c++
class Solution {
public:
    int maxDepth(Node* root) {
        
        // dfs
        if(!root) return 0;
        // for binary tree
        // return 1+max(maxDepth(root->left), maxDepth(root->right));
        
        // n-ary tree
        int depth=1, mx = 0;
        for(Node *t:root->children){
            mx = max(mx, maxDepth(t));
        }
        return 1+mx;
    }
};
```
#### bfs
```c++
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        queue<Node*> q({root});
        int depth = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                Node *  p =q.front(); 
                q.pop();
                for(Node *t:p->children) q.push(t);
            }
            depth++;
        }
        return depth;
    }
};

```