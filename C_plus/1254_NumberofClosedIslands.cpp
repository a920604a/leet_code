class Solution
{
public:
    void dfs(vector<vector<int> > &grid, int i, int j)
    {
        int n = grid.size(), m = grid[0].size();

        if (i < 0 || j < 0 || i > n - 1 || j > m - 1)
            return;
        if (grid[i][j] == 1)
            return;

        grid[i][j] = 1;
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
    }
    int closedIsland(vector<vector<int> > &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int ret = 0;
        // 先將周圍的島嶼淹掉
        for (int i = 0; i < n; ++i)
        {
            dfs(grid, i, 0);
            dfs(grid, i, m - 1);
        }
        for (int j = 0; j < m; ++j)
        {
            dfs(grid, 0, j);
            dfs(grid, n - 1, j);
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                    continue;
                dfs(grid, i, j);
                ret++;
            }
        }
        return ret;
    }
};