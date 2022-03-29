---
title: 102. Binary Tree Level Order Traversal
tags:  
    - bfs
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/binary-tree-level-order-traversal/)

## solution 

```c++
class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size-- >0){
                TreeNode *p = q.front();
                temp.push_back(p->val);
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`