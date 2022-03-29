---
title: 889. Construct Binary Tree from Preorder and Postorder Traversal
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)


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
    TreeNode * build(vector<int>& preorder, int l, int r, vector<int>& postorder, int lo, int hi){
        if(l>r || lo>hi) return nullptr;
        TreeNode* root = new TreeNode(preorder[l]);
        if(lo == hi )return root;
        int val = preorder[l+1], idx = -1;
        for(int i=lo;i<=hi;++i){
            if(val == postorder[i]){
                idx = i;
                break;
            }
        }
        root->left = build(preorder, l+1, l+1+idx-lo, postorder, lo, idx);
        root->right = build(preorder, l+1+idx-lo+1,r, postorder, idx+1, hi-1);
        return root;
        
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
```

## analysis
- time complexity `O(n^2)`
- space complexity `O(n^2)`  n is node number