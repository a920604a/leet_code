---
title: 1382. Balance a Binary Search Tree
tags:
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/balance-a-binary-search-tree/)

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
    void preorder(TreeNode*root, vector<int> & nums){
        if(!root) return;
        
        preorder(root->left, nums);
        nums.push_back(root->val);
        preorder(root->right, nums);
    }
    TreeNode *build(vector<int> & nums, int l, int r){
        if(l>r) return nullptr;
        
        int mid = l+(r-l)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build(nums, l, mid-1);
        root->right = build(nums, mid+1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        preorder(root, vec);
        return build(vec, 0, vec.size()-1);
    }
};
```

## analysis
- time complexity  `O(n)`
- space complexity `O(n)`