---
title: 111. Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        // dfs
        if(!root) return 0;
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        return 1+min(minDepth(root->left), minDepth(root->right));
    }
};
```

#### bfs
```c++
class Solution {
public:
    int minDepth(TreeNode* root) {
        // bfs
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int minDepth = 1;
        while(!q.empty()){
            int size  = q.size();
            for(int i=0;i<size; ++i){
                TreeNode *p = q.front();
                q.pop();
                
                if(!p->left && !p->right) return minDepth;
                else if(p->left && p->right){
                    q.push(p->left);
                    q.push(p->right);
                }
                else if(!p->left){
                    q.push(p->right);
                }
                else if(!p->right){
                    q.push(p->left);
                }
                
            }
            minDepth++;
        }
        return minDepth;
    }
};
```

## analysis

- backtracking 
time complexity `O(n)`
space complexity `O(logN)`
- bfs 
time complexity `O(n)`
space complexity `O(n)` , N/2 樹最底層的節點數量
