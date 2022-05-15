---
title: 1302. Deepest Leaves Sum
tags:
    - bfs
    - bracktracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/deepest-leaves-sum/)

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
    int deepestLeavesSum(TreeNode* root) {
        // BFS
        int ret = 0;
        if(!root) return 0;
        queue<TreeNode*> q({root});
        while(!q.empty()){
            int size = q.size();
            int temp =0;
            for(int i=0;i<size;++i){
                TreeNode *p = q.front(); q.pop();
                temp+=p->val;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            ret = temp;
        }
        return ret;
    }
};
```
## analysis
- time complecity `O(n)`, n is the number of node
- space complecity `O(n)`
