---
title: 105. Construct Binary Tree from Preorder and Inorder Traversal
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)


## solution

`preorder[l]`為根節點，並從`inorder[l:r]`找到該節點，並用此節點切割，左半部為此節點的左子樹，右半部為此節點的右子樹，並遞迴下去。


`root->left = build(preorder, pl+1, pl +idx-il, inorder, il, idx-1 );` 
為什麼不是`pl+1+idx-1-il+1` ? 因為`idx-1-il+1`是從跟節點開始計算offset，已包含 從pl開始找起的offset 所以不需再加一。

```c++
class Solution {
public:
    TreeNode *build(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir){
        if(pl>pr) return nullptr;
        TreeNode *root = new TreeNode(preorder[pl]);
        int idx = -1;
        for(int i=il;i<=ir;++i){
            if(root->val == inorder[i]){
                idx = i;
                break;
            }
        }
        root->left = build(preorder, pl+1, pl+1+idx-1-il, inorder, il, idx-1);
        root->right = build(preorder, pl+1+idx-1-il+1, pr, inorder,idx+1, ir);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
```

## analysis
- time complexity `O(n^2)`
- space complexity `O(n^2)`  n is node number