---
title: UnionFind
tags:  
    - Union Find
categories: 
    - CS
    - Algorithm
comments: false
---

method : connect、find、unionSet

- 130 Surrounded Regions
- 990 Satisfiability of Equality Equations


- 547 Number of Provinces
- 947 Most Stones Removed with Same Row or Column 


## 框架
```cpp
class UF{
private:
    vector<int> size, parent;
    int count;
public:
    UF(int n){
        size = vector<int>(n);
        parent = vector<int>(n);
        int count = n;
        
        for(int i=0;i<n;++i){
            size[i] = 1;
            parent[i] = i;
        }
    }
    bool connect(int p , int q){
        int pRoot = find(p);
        int qRoot = find(q);
        return  pRoot == qRoot;
        }
    int find(int x){
        while(x != parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    
    void unionSet(int p , int q){
        int pRoot = find(p);
        int qRoot = find(q);
        if(pRoot == qRoot ) return ;
        
        if(size[pRoot] >= size[qRoot]){
            parent[qRoot] = pRoot;
            size[pRoot] += size[qRoot];
        }
        else{
            parent[pRoot] = qRoot;
            size[qRoot] += size[pRoot];            
        }
    }
    
};
```
