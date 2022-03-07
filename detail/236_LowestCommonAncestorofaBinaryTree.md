---
title: 236. Lowest Common Ancestor of a Binary Tree
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)


## solution


##### option 1 

- 先遞迴檢查 `p`和`q` 是否在`root`的左子樹
- 如果都在左子樹，則往左子樹搜尋
- 如果都不在，則往右子樹搜尋
- 其餘狀況，則`return root`

```c++
class Solution {
public:
    bool cover(TreeNode * node, TreeNode * p){
        if(!node) return false;
        if(node==p) return true;
        return cover(node->left, p) || cover(node->right,p); 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        bool pchild = cover(root->left, p);
        bool qchild = cover(root->left, q);
        if(pchild && qchild) return lowestCommonAncestor(root->left, p, q);
        else if(!pchild && !qchild) return lowestCommonAncestor(root->right, p, q);
        return root;      
    }
};
```

#### option 2 - dfs + postorder traverse

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root) return root;
        if(root == p || root == q) return root;
        // post-order
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if(l && !r) return l;
        else if(r && !l) return r;
        else if(l && r) return root;
        return nullptr;
    }
};
```

## analysis
- option 1 
    - time complexity `O(t)` t is the size of the subtree for the first common ancestor on average case, `O(n)` on worst case, n is number of nodes in BT
    - space complexity `O(h)`
- option 2
    - time complexity `O(n)` n is number of nodes in BT
    - space complexity `O(h)` h is the height of BT