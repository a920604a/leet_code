---
title: 652. Find Duplicate Subtrees
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/find-duplicate-subtrees/)

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
    unordered_map<string, int> memo;
    string checkDuplicate(TreeNode * root, vector<TreeNode*> & ret){
        if(!root) return "#";
        
        string cur ;
        cur += checkDuplicate(root->left, ret) + ",";
        cur += checkDuplicate(root->right, ret) + ",";
        cur+= to_string(root->val);
        if(memo.find(cur)!=memo.end() && memo[cur] ==1){
            ret.push_back(root);
            
        }
        memo[cur]++;
        return cur;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>  ret;
        checkDuplicate(root, ret);
        return ret;
    }
};
```
## analysis
