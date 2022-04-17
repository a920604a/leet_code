---
title: 897. Increasing Order Search Tree
tags:
    - backtracking
    - bfs
    - stack
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/increasing-order-search-tree/)
## solution 
#### option 1 - extra space
```c++
class Solution {
public:
    vector<int> vec;
    void preorder(TreeNode *root){
        if(!root) return;
        preorder(root->left);
        vec.push_back(root->val);
        preorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        preorder(root);
        TreeNode *p = new TreeNode(-1), *ans = p;
        for(int val:vec){
            p->right = new TreeNode(val);
            p=p->right;
        }
        return ans->right;
        
    }
};
```

#### option 2 - without extra space
```c++
class Solution {
public:
    TreeNode * p = new TreeNode(-1);
    void preorder(TreeNode *root){
        if(!root) return;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = nullptr;
        root->right = nullptr;
        
        preorder(left);
        
        p->right = root;
        p=p->right;
        preorder(right);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *ans = p;;
        preorder(root);
        return ans->right;
        
    }
};
```

