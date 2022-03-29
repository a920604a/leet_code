---
title: 104. Maximum Depth of Binary Tree

tags:  
    - backtracking
    - bfs
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

求二元樹的最大深度

## solution

#### dfs
- 用遞迴方式，求二元樹的深度，終止條件為當節點不存在時`return 0`，否則`1+max(maxDepth(root->left), maxDepth(root->right))`
```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        else return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};
```

#### bfs
- 用bfs，用queue輔助，儲存拜訪當下節點的左右子節點，並將深度加一
```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root) return 0;
        int depth = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                TreeNode *p = q.front();
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            depth++;
        }
        return depth;
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
