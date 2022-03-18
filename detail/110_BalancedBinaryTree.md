---
title: 110. Balanced Binary Tree
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/balanced-binary-tree/)

## solution

```c++
class Solution {
public:
    int Depth(TreeNode *root){
        if(!root) return 0;
        return 1+max( Depth(root->left), Depth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        // determine the height of the children
        int left = Depth(root->left);
        int right = Depth(root->right);
        if(abs(right-left)>1) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
};

```

```c++
class Solution {
public:
    bool ret;
    int depth(TreeNode *root){
        if(!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        if(abs(left- right)>1){
            ret =false;
        }
        return 1+max(left, right);
        
    }
    bool isBalanced(TreeNode* root) {
        ret = true;
        depth(root);
        return ret;
        
    }
};
```