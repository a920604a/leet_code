---
title: 106. Construct Binary Tree from Inorder and Postorder Traversal
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)


## solution

`postorder[r]`為根節點，並從`inorder[l:r]`找到該節點，並用此節點切割，左半部為此節點的左子樹，右半部為此節點的右子樹，並遞迴下去。

```c++
class Solution {
public:
    TreeNode *build(vector<int> & inorder, int il, int ir, vector<int>& postorder, int pl, int pr){
        if(il>ir) return nullptr;
        TreeNode *root = new TreeNode(postorder[pr]);
        int idx = -1;
        for(int i= il;i<=ir;++i){
            if(inorder[i] == root->val){
                idx = i ;
                break;
            }
        }
        root->left = build(inorder, il, idx-1, postorder, pl, pl+idx-il-1) ;
        root->right = build(inorder, idx+1, ir, postorder, pl+idx-il, pr-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};
```

## analysis
- time complexity `O(n^2)`
- space complexity `O(n^2)`  n is node number