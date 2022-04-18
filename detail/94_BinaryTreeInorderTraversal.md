---
title: 94. Binary Tree Inorder Traversal
tags: 
    - backtracking
    - stack
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/binary-tree-inorder-traversal/)

## solution
#### option 1 - dfs
```c++

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ret){
        if(!root) return;
        inorder(root->left, ret);
        ret.push_back(root->val);
        inorder(root->right, ret);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorder(root, ret);
        return ret;
    }
};
```

#### option 2 - iterative + stack
```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> sta;
        TreeNode *p = root;
        vector<int> ret;
        while (p || !sta.empty()) {
            while (p) { // L
                sta.push(p);
                p=p->left; 
            }
            p = sta.top();
            sta.pop();
            ret.push_back(p->val);  // V
            p = p->right;   // R
            
            
        }
        return ret;
    }
};
```