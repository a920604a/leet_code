---
title: 114. Flatten Binary Tree to Linked List
tags:  
    - backtracking
categories: leetcode
---



## [problem](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

## solution
```c++
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
    
        flatten(root->left);
        flatten(root->right);

        TreeNode * temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode *p = root;
        while(p->right) p=p->right;
        p->right = temp;
    
    }
};

```
## analysis
- time complexity `O(n)`
- space complexity `O(1)`