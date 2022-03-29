---
title: 100. Same Tree

tags:  
    - bfs
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/same-tree/)

## solution 

#### option 1 - backtracking
```c++
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
    }
};
```
#### option 2 - bfs
```c++
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!q && !p) return true;
        if(!q ^ !p) return false;
        queue<TreeNode *>q1, q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            int size  = q1.size();
            if(size !=q2.size()) return false;
            while(size-->0){
                TreeNode *t1 = q1.front(), *t2 = q2.front();
                q1.pop();
                q2.pop();
                if(t1->val !=t2->val) return false;
                if(t1->left && t2->left){
                    q1.push(t1->left);
                    q2.push(t2->left);
                }
                else if(!t1->left ^ !t2->left) return false;
                if(t1->right && t2->right){
                    q1.push(t1->right);
                    q2.push(t2->right);
                }
                else if(!t1->right ^ !t2->right) return false;
            }
        }
        if(!q1.empty() || !q2.empty()) return false;
        return true;
    }
} ;
```

## analysis
- option 1
    - time complexity `O(n)` n is node
    - space complexity `O(h)` h is height or depth
- option 2
    - time complexity `O(n)` n is node
    - space complexity `O(n)` n is node