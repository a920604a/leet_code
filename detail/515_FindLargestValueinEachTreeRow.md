---
title: 515. Find Largest Value in Each Tree Row
tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/find-largest-value-in-each-tree-row/)

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
    vector<int> largestValues(TreeNode* root) {
        // bfs 
        vector<int> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int mx = q.front()->val;
            for(int i=0;i<size;++i){
                TreeNode *p = q.front();
                q.pop();
                mx = max(mx, p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                
            }
            ret.push_back(mx);
        }
        return ret;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`