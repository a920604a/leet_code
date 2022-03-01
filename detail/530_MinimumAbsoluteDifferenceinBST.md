---
title: 530. Minimum Absolute Difference in BST
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)

## solution

#### option 1
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
    void inorder(TreeNode *root, vector<int> & ret){
        if(!root) return ;
        
        inorder(root->left, ret);
        ret.push_back(root->val);
        inorder(root->right, ret);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> ret;
        inorder(root, ret);
        // ret is increasing array
        int ans = ret[1] - ret[0], n= ret.size();
        for(int i=2;i<n;++i){
            ans = min(ans, ret[i] - ret[i-1]);
        }
        return ans;
    }
};
```

#### option 2
需要多一個節點或是int大小空間紀錄上一次拜訪到的節點
```c++
class Solution {
public:
    void inorder(TreeNode *root, TreeNode* & prev, int &diff){
        if(!root) return;
        
        
        inorder(root->left, prev, diff);
        
        // 最小值位置
        if(prev == nullptr){
            prev = root;
        }
        else{
            diff = min(root->val - prev->val, diff);
            // 拜訪完，要更新prev
            prev = root;
        }
        
        
        inorder(root->right,prev,  diff);
    }
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        // pre 存取上一個拜訪的節點
        TreeNode *pre = nullptr;
        inorder(root,pre,  diff);
        return diff;
    }
};
```