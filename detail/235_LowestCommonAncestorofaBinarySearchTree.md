---
title: 235. Lowest Common Ancestor of a Binary Search Tree
tags:  
    - backtracking
categories: leetcode
comments: false
---


## [problem](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

> Follow up [236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)


## solution

- 比較`root` `p` `q` 三個節點的值
- 如果`root->val` 是其他兩個節點的值，則`return root`
- 如果`root->val` 小於其他兩節點的值，則向`root->right` 搜尋
- 如果`root->val` 大於其他兩節點的值，則向`root->left` 搜尋
- 剩餘狀況，則`return root`

#### option 1 - recursive

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == q || root==q) return root;
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p,q);
        else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p,q);
        return root;
    }
};
```

> `if(root->val > p->val && root->val > q->val)` 可改成
> `if(root->val > max(p->val, q->val) )`
- postorder
沒用到BST特性
```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root ==p || root==q) return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        
        if( l && r) return root;
        else if(!l) return r;
        return l;
    }
};
```
#### option 2 - iterative
不斷更新root 節點

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(root ==p || root==q) return root;
            else if(root->val > p->val && root->val > q->val) root = root->left;
            else if(root->val < p->val && root->val < q->val) root = root->right;
            else return root;
        }
        return nullptr;
    }
};
```
## analysis
- time complexity `O(n)` n is node number of tree
- space complexity `O(h)` h is height of tree