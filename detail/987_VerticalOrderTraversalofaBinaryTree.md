---
title: 987. Vertical Order Traversal of a Binary Tree
tags:
    - hash table
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ret;
        map<int, map<int,vector<int>> > m;
        queue<pair<TreeNode*, vector<int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            auto t = q.front(); q.pop();
            TreeNode *node = t.first ;
            int x = t.second[0], h = t.second[1];
            m[x][h].push_back(node->val);
            if(node->left) q.push({node->left, {x-1, h+1}});
            if(node->right) q.push({node->right, {x+1, h+1}});
        }
        
        for(auto &a :m){
            vector<int> col;
            for(auto &it :a.second){
                sort(it.second.begin(), it.second.end());
                for(int v:it.second) col.push_back(v);
            }
            ret.push_back(col);
        }
        
        return ret;
        
    }
};
```