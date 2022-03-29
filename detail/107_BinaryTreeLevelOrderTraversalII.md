---
title: 107. Binary Tree Level Order Traversal II
tags:  
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;++i){
                TreeNode * p = q.front();
                q.pop();
                level.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            ret.push_back(level);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`

