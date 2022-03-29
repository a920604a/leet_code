---
title: 429. N-ary Tree Level Order Traversal

tags: 
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size; ++i){
                Node *p = q.front();
                q.pop();
                level.push_back(p->val);
                for(Node *n:p->children) q.push(n);
            }
            ret.push_back(level);
        }
        
        return ret;
    }
};

```