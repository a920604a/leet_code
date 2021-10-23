class Solution
{
public:
    void isLand(vector<vector<char> > &grid, int i, int j, vector<vector<bool> > &visit)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || visit[i][j] || grid[i][j] == '0')
            return;

        visit[i][j] = true;
        isLand(grid, i - 1, j, visit);
        isLand(grid, i + 1, j, visit);
        isLand(grid, i, j - 1, visit);
        isLand(grid, i, j + 1, visit);
    }
    int numIslands(vector<vector<char> > &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool> > visit(m, vector<bool>(n));
        int ret = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '0' || visit[i][j])
                    continue;
                ret++;
                isLand(grid, i, j, visit);
            }
        }

        return ret;
    }
};



// option 2 
void dfs(vector<vector<char>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1 || grid[i][j]=='0') return;
        
        grid[i][j] = '0';
        dfs(grid, i-1,j);
        dfs(grid, i,j-1);
        dfs(grid, i+1,j);
        dfs(grid, i,j+1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == '0') continue;
                dfs(grid,i, j);
                cnt++;
            }
        }
        return cnt;
    }
