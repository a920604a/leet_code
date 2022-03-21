---
title: 95. Unique Binary Search Trees II
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/unique-binary-search-trees-ii/)
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
    vector<TreeNode*> generateTrees(int l, int r){
        if(l>r) return {nullptr};
        vector<TreeNode *> ret;
        for(int i=l;i<=r;++i){
            vector<TreeNode*> left = generateTrees(l, i-1);
            vector<TreeNode*> right = generateTrees(i+1, r);
            for(auto l:left){
                for(auto r:right){
                    TreeNode *t = new TreeNode(i);
                    t->left = l;
                    t->right = r;
                    ret.push_back(t);
                }
            }
            
        }
        return ret;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);      
    }
};
```
- memo pattern
```c++
class Solution {
public:
    vector<vector<vector<TreeNode*>>> memo;
    vector<TreeNode*> generateTrees(int l, int r){
        if(l>r) return {nullptr};
        if(!memo[l][r].empty()) return memo[l][r];
        vector<TreeNode *> ret;
        for(int i=l;i<=r;++i){
            vector<TreeNode*> left = generateTrees(l, i-1);
            vector<TreeNode*> right = generateTrees(i+1, r);
            for(auto l:left){
                for(auto r:right){
                    TreeNode *t = new TreeNode(i);
                    t->left = l;
                    t->right = r;
                    ret.push_back(t);
                }
            }
            
        }
        return  memo[l][r] = ret;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        memo = vector<vector<vector<TreeNode * >>>(n+1, vector<vector<TreeNode*>>(n+1));
        return generateTrees(1, n);
        
        
    }
};
```
## analysis
- time complexity `O(n^2)`