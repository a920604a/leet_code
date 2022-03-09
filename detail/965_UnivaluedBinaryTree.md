---
title: 965. Univalued Binary Tree
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/)

## solution

#### dfs
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
    void isUnval(TreeNode * root, bool &ret, int & val){
        
        if(!root) return ;
        //preorder
        if(root->val !=val){
            ret = false;
            return;
        }
        
        isUnval(root->left, ret, val);
        isUnval(root->right, ret, val);
        
        
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        bool ret = true;
        int val = root->val;
        isUnval(root, ret, val);
        return ret;
        
    }
};
```

```c++
class Solution {
public:
    
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        // preorder
        if(root->left && root->left->val !=root->val) return false;
        if(root->right && root->right->val !=root->val) return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
```

#### bfs
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
    void isUnval(TreeNode * root, bool &ret, int & val){
        
        if(!root) return ;
        //preorder
        if(root->val !=val){
            ret = false;
            return;
        }
        
        isUnval(root->left, ret, val);
        isUnval(root->right, ret, val);
        
        
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        int val = root->val;
        queue<TreeNode*> q({root});
        while(!q.empty()){
            TreeNode *p = q.front();
            q.pop();
            if(p->val !=val) return false;
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        return true;
        
    }
};
```