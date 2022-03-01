---
title: 98. Validate Binary Search Tree
tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/validate-binary-search-tree/)


## solution

#### option 1 - inorder traverse
按照inorder 拜訪每一節點，並存到vector，拜訪完，檢查vector是否為單調遞增陣列即可。

#### option 2 - dfs
拜訪每一個節點，並檢查該節點的值介於左右孩子的值
```c++
class Solution {
public:
    bool isValidBST(TreeNode *root, long mn, long mx){
        if(!root) return true;
        
        if(root->val <= mn || root->val >= mx ) return false;
        return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val , mx);
        
    }
    bool isValidBST(TreeNode* root) {
        // avoid overflow
        long mx = LONG_MAX, mn =LONG_MIN;
        return isValidBST(root, mn, mx);
    }
};
```

#### option 3
請參考 `morris traversal` 可以做到 `O(1)` space


```c++
class Solution {
public:
    bool isValid(TreeNode* root, long l, long r){
        
        if(!root) return true;
        if(root->val <= l || root->val >= r) return false;
        return isValid(root->left, l, root->val) && isValid(root->right, root->val, r);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
        
    }
};
```
## analysis
- optnio 1
    - time complexity `O(n)`
    - space complexity `O(n)`  
- option 2
    - time complexity `O(n)`
    - space complexity `O(h)`  since recursive inorder traversal will lead to stack frame creation equal to the height of the tree. 