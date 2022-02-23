---
title: 133. Clone Graph
tags:  
    - Graph
    - dfs
    - bfs
    - hash table
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/clone-graph/)

## solution

#### option 1 - dfs


```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> visited;
public:
    Node * dfs(Node *node){
        if(visited.find(node)!=visited.end()) return visited[node];
        
        if(!node) return nullptr;
        
        Node* clone = new Node(node->val);
        visited[node] = clone;
        for(Node * n:node->neighbors){
            clone->neighbors.push_back(dfs(n));
        }
        return visited[node];
    }
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
```
#### option 2 - bfs

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> copies;
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        Node* copy = new Node(node -> val, {});
        copies[node] = copy;
        queue<Node *>q;
        q.push(node);
        while(!q.empty()){
            Node *cur = q.front();
            q.pop();
            for(Node *neighbor:cur->neighbors){
                if(copies.find(neighbor)==copies.end()){
                    copies[neighbor] = new Node(neighbor->val, {});
                    q.push(neighbor);
                }
                copies[cur] -> neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;
    }
};
```

## analysis
- time complexity `O(n+m)`, n is the number of nodes and m is the number of edges
- sparse complexity `O(n)`