---
title: 117. Populating Next Right Pointers in Each Node II
tags:  
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

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
    
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                Node * p = q.front();
                q.pop();
                if(i!=size-1) p->next= q.front();
                else p->next = nullptr;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        return root;
        
    }
};
```

## analysis
- time complexity `O(n)`
- space complexity `O(n)`