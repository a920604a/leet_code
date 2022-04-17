---
title: 2236. Root Equals Sum of Children
categories: leetcode
comments: false
---
## [problem](https://leetcode.com/problems/root-equals-sum-of-children/
## solution
```c++
class Solution {
public:
    bool checkTree(TreeNode* root) {
        // exactly 3 nodes
        return root->val == root->left->val +root->right->val;
        
    }
};
```