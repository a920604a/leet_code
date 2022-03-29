---
title: 589. N-ary Tree Preorder Traversal
tags: 
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)

## solution
```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void preorder(Node *root, vector<int> & ret){
        if(!root) return;
        ret.push_back(root->val);
        
        for(Node *p : root->children){
            preorder(p, ret);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> ret;
        preorder(root, ret);
        return ret;
        
    }
};
```