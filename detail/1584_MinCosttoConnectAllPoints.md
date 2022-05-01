---
title: 1584. Min Cost to Connect All Points
tags:  
    - Union Find
    - Kruskal
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/min-cost-to-connect-all-points/)
## solution 
#### Kruskal, TLE
```c++
class UnionFind{
private:
    vector<int> size, parent;
    int count ;
public:
    UnionFind(int n){
        count = n;
        size = vector<int>(n,1);
        parent = vector<int>(n,0);
        for(int i=0;i<n;++i){
            parent[i]=i;
        }
    }
    void unionSet(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ) return ;
        if(size[rootP] > size[rootQ]){
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else{
            parent[rootP] = rootQ;
            size[rootQ] +=size[rootP];
        }
        count--;
    }
    bool connected(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        return rootP==rootQ;
    }
    int find(int x){
        while(parent[x]!=x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    int getcount(){ return count;}

};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 1. 建立一個資料結構，將邊長也考慮進去
        int n = points.size();
        vector<vector<int>> edges ;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int xi = points[i][0], yi = points[i][1];
                int xj = points[j][0], yj = points[j][1];
                edges.push_back({i,j, abs(xi-xj)+abs(yi-yj)});
            }
        }
        // 2. 權重從小至大排序
        sort(edges.begin(), edges.end(), [](const auto& a, const auto &b)->bool {
            return a[2]<b[2];
        });
        int mst = 0;
        UnionFind uf(n);
        // 3. 從權值最小的邊開始，如果這條邊連接的兩個節點於圖G 中不在同一個連通分量中，則添加這條邊到圖 G 中
        // 4. 重複3，直至圖G中所有的節點都在同一個連通分量中
        for(const auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if(uf.connected(u,v)) continue;
            // if(uf.getcount() == 1) break;
            mst+=weight;
            uf.unionSet(u,v);
        }
        return mst;
    }
};
```
## analysis
- Kruskal
    - time complexity `O(V+E)`
    - space complexity `O(ElogE)`
