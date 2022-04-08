---
title: 547. Number of Provinces
tags: 
    - Uniod Find
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/number-of-provinces/)
## solution
```c++
class UnionFind{
public:
    vector<int> size, parent;
    int count;
    UnionFind(int cap){
        parent = vector<int>(cap, 0);
        size = vector<int>(cap, 1);
        count = cap;
        for(int i=0;i<cap;++i){
            parent[i] = i;
        }
    }
    bool connect(int p, int q){
        int pRoot = find(p);
        int qRoot = find(q);
        return pRoot == qRoot;
    }
    int find(int x){
        while(x!=parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void unionSet(int p, int q){
        int pRoot = find(p);
        int qRoot = find(q);
        if(pRoot == qRoot) return ;
        if(size[pRoot] >= size[qRoot]){
            size[pRoot] +=size[qRoot];
            parent[qRoot] = parent[pRoot];
        }
        else{
            size[qRoot] +=size[pRoot];
            parent[pRoot] = parent[qRoot];
        }
    }
    int getCount(){
        int ret = 0;
        for(int i=0;i<count;++i){
            if(parent[i] == i) ret++;
        }
        return ret;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind *uf = new UnionFind(n);
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(isConnected[i][j] == 1) uf->unionSet(i,j);
            }
        }
        
        return uf->getCount();
    }
};

```
