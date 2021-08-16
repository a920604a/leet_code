# Graph

###### tags: `interview` `algorithm`


```cpp
/* 多叉树遍历框架 */
void traverse(TreeNode root) {
    if (root == null) return;

    for (TreeNode child : root.children)
        traverse(child);
}

// 有環的圖
Graph graph;
boolean[] visited;

/* 图遍历框架 */
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

