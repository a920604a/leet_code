# Graph

###### tags: `interview` `algorithm`



- 797 All Paths From Source to Target (Medium) 

- 207 Course Schedule (Medium)
- 210 Course Schedule II (Medium)

Dijstrka
- 743 Network Delay Time (Medium)
- 1514 Path with Maximum Probability (Medium)
- 1631 Path With Minimum Effort (Medium)

- 785 Is Graph Bipartite? (Medium)
- 886 Possible Bipartition (Medium)

- 277 Find the Celebrity (Medium, Premium)


Kruskal
- 261 Graph Valid Tree (Medium, Premium)
- 1135 Connecting Cities With Minimum Cost (Medium, Premium)
- 1584 Min Cost to Connect All Points (Medium)


Union-Find

- 130 Surrounded Regions
- 990 Satisfiability of Equality Equations
- 547 Number of Provinces

補充
- 133 Clone Graph (Medium)
- 787 Cheapest Flights Within K Stops (Medium) 




#### 多個子樹的樹 - 圖的前身
```c++
/* 多叉树遍历框架 */
void traverse(TreeNode root) {
    if (root == null) return;

    for (TreeNode child : root.children)
        traverse(child);
}
```
#### 圖

圖可能會有環，所以需要另外空間去紀錄拜訪過的點

```c++
// 有環的圖
Graph graph;
boolean[] visited;

/*`图遍历框架 */
void traverse(Graph graph, int s) {
    if (visited[s]) return;
    // 经过节点 s
    visited[s] = true;
    for (TreeNode neighbor : graph.neighbors(s))
        traverse(neighbor);
    // 离开节点 s
    visited[s] = false;   
}
// 有向圖含有環的時候才需要 visited 數組輔助。
// 如果沒有環，連visited 都可以省略了，等同於樹的遍歷

```

