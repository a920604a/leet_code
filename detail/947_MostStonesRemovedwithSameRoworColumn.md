---
title: 947. Most Stones Removed with Same Row or Column
tags:
    - Union Find
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)

## solution 

```c++
class UnionFind{
private:
    vector<int> parent, size;
    int count;
public:
    UnionFind(int n){
        parent = vector<int>(n);
        size = vector<int>(n);
        count = n;
        for(int i=0;i<n;++i){
            parent[i] = i;
            size[i] = 1;
        }
    }
    bool connect(int p, int q){
        int pRoot = find(p);
        int qRoot = find(q);
        return pRoot == qRoot;
    }
    int find(int x){
        while(parent[x]!=x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void unionSet(int p, int q){
        int pRoot = find(p);
        int qRoot = find(q);
        if(pRoot == qRoot) return;
        if(size[pRoot]>=size[qRoot]){
            parent[qRoot] = parent[pRoot];
            size[pRoot] += size[qRoot];
        }
        else{
            parent[pRoot] = parent[qRoot];
            size[qRoot] += size[pRoot];
        }
        
    }
    void print(){
        // for debug
        for(int p:parent) cout<<p<<" ";
        cout<<endl;
        for(int s:size) cout<<s<<" ";
        cout<<endl;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind * uf = new UnionFind(n);
        for(int i= 0;i<n;++i){
            for(int j = i+1;j<n ; ++j){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    uf->unionSet(i,j);
                }
            }
        }
        // uf->print();
        unordered_set<int> s;
        for(int i=0;i<n;++i){
            s.insert(uf->find(i));
        }
        return  n - s.size() ;
        
    }
};
```