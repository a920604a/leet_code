---
title: 590. N-ary Tree Postorder Traversal

tags: 
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/n-ary-tree-postorder-traversal/)

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
    void postorder(Node *root, vector<int> & ret){
        if(!root) return;
        
        
        for(Node *p : root->children){
            postorder(p, ret);
        }
        ret.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ret;
        postorder(root, ret);
        return ret;
        
    }
};

```