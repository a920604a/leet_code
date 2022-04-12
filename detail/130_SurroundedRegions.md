---
title: 130. Surrounded Regions
tags:  
    - backtracking
    - bfs
    - Union Find
categories: leetcode
comments: false
---

## [problem](https://leetcode.com/problems/surrounded-regions/)

## solution
#### option 1 - dfs
```c++
class Solution {
public:
    void dfs(vector<vector<char>> & board, int i, int j){
        int n = board.size(), m = board[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1 || board[i][j] != 'O') return;
        board[i][j] = '#';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
        
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        // 將周圍 圈圈及觸及到周圍的圈圈先改成#
        for(int i=0;i<n;++i){
            if(board[i][0] =='O') dfs(board,i, 0);
            if(board[i][m-1] == 'O') dfs(board,i, m-1);
        }
        for(int j = 0;j<m;++j){
            if(board[0][j] == 'O') dfs(board,0, j);
            if(board[n-1][j] == 'O') dfs(board,n-1, j);
        }
        // 將剩下的圈圈改成X
        for(int i=0;i<n;++i){
            for(int j= 0 ;j<m;++j){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
```

#### option 2 - BFS
```c++
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        for(int i= 0 ;i<n;++i){
            for(int j = 0;j<m;++j){
                if(i==0 || i==n-1 || j ==0 || j == m-1){
                    if(board[i][j] !='O' ) continue;
                    board[i][j] = '$';
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        auto p = q.front();q.pop();
                        for(auto d:dirs){
                            int x = p.first+d[0] , y = p.second+d[1];
                            if(x>=0 && x<n && y>=0 && y<m && board[x][y] == 'O' ) {
                                board[x][y] = '$';
                                q.push(make_pair(x,y));
                            }
                        }
                        
                    }
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
};
```
#### option 3 - Union Find
```c++

class UF
{
private:
    int count;
    vector<int> parent;
    vector<int> size;

public:
    UF(int n)
    {
        count = n;
        parent = vector<int>(n);
        size = vector<int>(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void unionSet(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;

        if (size[rootP] > size[rootQ])
        {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else
        {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }
    // 判斷p q 是否互相連通
    bool connected(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        return rootQ == rootP;
    }
    // 返回 節點 x 的根節點
    int find(int x)
    {
        while (parent[x] != x)
        {
            // 進行路徑壓縮
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    int length()
    {
        return count;
    }
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        UF *uf = new UF(m * n + 1);
        int dummy = m * n;
        // 首行與末行的O與dummy 連通
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
                uf->unionSet(i * n, dummy);
            if (board[i][n - 1] == 'O')
                uf->unionSet(i * n + n - 1, dummy);
        }

        // 首列與末列的O與dummy 連通
        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O')
                uf->unionSet(j, dummy);
            if (board[m - 1][j] == 'O')
                uf->unionSet(n * (m - 1) + j, dummy);
        }

        vector<vector<int> > action = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        for (int i = 1; i < m - 1; ++i)
        {
            for (int j = 1; j < n - 1; ++j)
            {
                if (board[i][j] == 'O')
                {
                    // 将此 O 与上下左右的 O 连通
                    for (int k = 0; k < 4; ++k)
                    {
                        int x = i + action[k][0];
                        int y = j + action[k][1];
                        if (board[x][y] == 'O')
                            uf->unionSet(x * n + y, i * n + j);
                    }
                }
            }
        }
        // 所有不和 dummy 连通的 O，都要被替换
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (!uf->connected(dummy, i * n + j))
                    board[i][j] = 'X';
            }
        }      
    }
};
```