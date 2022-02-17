# 200. Number of Islands
###### tags: `leetcode`  `backtracking` `bfs` `Union Find` `Blind Curated 75`


## [problem](https://leetcode.com/problems/number-of-islands/)

## solution

#### option 1 - backtracking
將拜訪過的位置，原地修改其陣列的值為 `0`

```c++
class Solution {
public:
    void traverse(vector<vector<char>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1 || grid[i][j] =='0') return;
        grid[i][j] = '0';
        traverse(grid, i-1, j);
        traverse(grid, i+1, j);
        traverse(grid, i, j-1);
        traverse(grid, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(grid[i][j] == '1'){
                    traverse(grid, i, j);
                    count++;
                }
            }
        }
        return count;
        
    }
};
```


#### option 2 bfs

```c++
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        vector<int> dirX = {-1,1,0,0}, dirY = {0,0,-1,1};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(grid[i][j] == '0' || visited[i][j]) continue;
                queue<int> q;
                q.push(i*m+j);
                while(!q.empty()){
                    int p = q.front();
                    q.pop();
                    grid[p/m][p%m] = '0';
                    visited[p/m][p%m] = true;
                    for(int d = 0;d<4;++d){
                        int x =p/m + dirX[d], y = p%m + dirY[d];
                        if(x< 0 || y<0 || x>n-1 || y>m-1 || grid[x][y] == '0' || visited[x][y]) continue;
                        q.push(x*m +y);
                        visited[x][y] = true;
                    }
                }
                count++;
            }
        }
        return count;
    }
};
```
#### option 3 - *Union Find
## analysis
- option 1 
    - time complexity `O(n*m)` 
    - space complexity `O(n*m)`
