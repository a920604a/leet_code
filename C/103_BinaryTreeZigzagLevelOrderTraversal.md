---
title: 103. Binary Tree Zigzag Level Order Traversal
tags: 
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

## solution
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode *> q;
        q.push(root);
        int h = 1;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size; ++i){
                TreeNode * p = q.front();
                q.pop();
                level.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);            
            }
            if(h%2==0){
                reverse(level.begin(), level.end());
            }
            h++;
            ret.push_back(level);
        }
        return ret;
    }
};
```