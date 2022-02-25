---
title: 116. Populating Next Right Pointers in Each Node
 Postorder Traversal
tags:  
    - backtracking
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)

## solution
```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connect(Node *left, Node* right){
        if(!left && !right) return;
        
        left->next = right;
        connect(left->right, right->left);
        connect(right->left, right->right);
        connect(left->left, left->right);
    }
    Node* connect(Node* root) {
        if(!root) return root;
        connect(root->left, root->right);
        return root;
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`