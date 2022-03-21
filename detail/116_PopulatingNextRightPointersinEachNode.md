---
title: 116. Populating Next Right Pointers in Each Node
 Postorder Traversal
tags:  
    - backtracking
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)

## solution
#### option 1 - dfs
```c++
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

#### option 2 - bfs
```c++
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node *>q({root});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                Node *p = q.front(); q.pop();
                if(i==size-1) p->next = nullptr;
                else p->next = q.front();
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
- space complexity `O(1)`