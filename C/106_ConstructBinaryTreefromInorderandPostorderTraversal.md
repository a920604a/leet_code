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
    TreeNode* build(vector<int> & inorder, vector<int>& postorder, int il, int ir, int pl, int pr){
        
        if(il>ir || pl>pr) return nullptr;
        int idx = -1, val = postorder[pr];
        TreeNode *root= new TreeNode(val);
        for(int i=il;i<=ir;++i){
            if(val==inorder[i]){
                idx = i;
                break;
            }
        }
        root->left = build(inorder, postorder, il, idx-1, pl, pl+idx-il-1);
        root->right = build(inorder, postorder, idx+1, ir, pl+idx-il, pr-1);;
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);    
        
    }
};
```

## analysis
- time complexity `O(n^2)`
- space complexity `O(n^2)`  n is node number