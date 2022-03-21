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
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        int depth = 1;
        queue<pair<TreeNode*,int>> q  ;
        q.push({root, depth});
        while(!q.empty()){
            vector<int> rec;
            int size = q.size();
            for(int i=0;i<size; ++i){
                auto [p,d] = q.front();
                q.pop();
                
                if(p->left) {
                    q.push({p->left, d+1});
                    rec.push_back(p->left->val);
                }
                else rec.push_back(-101);
                if(p->right){
                    q.push({p->right, d+1});
                    rec.push_back(p->right->val);
                } 
                else rec.push_back(-101);
            }
            // check is palindrome
            int l=0, r = rec.size()-1;
            while(l<r){
                if(rec[l++]!=rec[r--]) return false;
            }
            
        }
        return true;
    }
};
```