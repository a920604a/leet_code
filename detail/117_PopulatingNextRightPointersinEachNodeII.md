---
title: 117. Populating Next Right Pointers in Each Node II
tags:  
    - bfs
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

## solution
#### option 1 - bfs
```c++
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
#### option 2 - dfs
```c++
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node * p = root->next;
        while(p){
            if(p->left){
                p=p->left;
                break;
            }
            if(p->right){
                p=p->right;
                break;
            }
            p=p->next;
            
        }
        if(root->right) root->right->next = p;
        if(root->left) root->left->next = root->right?root->right:p;
        connect(root->right);
        connect(root->left);
        
        return root;
    }
};
```
## analysis
- time complexity `O(n)`
- space complexity `O(n)`