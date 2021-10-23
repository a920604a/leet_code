class Solution
{
public:
    void dfs(vector<vector<int> > &grid, int i, int j, int &area)
    {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i > n - 1 || j > m - 1 || grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        area++;
        dfs(grid, i - 1, j, area);
        dfs(grid, i, j - 1, area);
        dfs(grid, i + 1, j, area);
        dfs(grid, i, j + 1, area);
    }
    int numEnclaves(vector<vector<int> > &grid)
    {

        // 先將周圍島嶼淹掉，再計算剩餘島嶼的總面積大小
        int n = grid.size(), m = grid[0].size();
        int totalArea = 0, area;
        for (int i = 0; i < n; ++i)
        {
            dfs(grid, i, 0, area);
            dfs(grid, i, m - 1, area);
        }
        for (int j = 0; j < m; ++j)
        {
            dfs(grid, 0, j, area);
            dfs(grid, n - 1, j, area);
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                // option 1
                // if(grid[i][j] == 0) continue;
                // area = 0;
                // dfs(grid, i, j, area);
                // totalArea += area;

                //option 2
                totalArea += (grid[i][j] == 1);
            }
        }
        return totalArea;
    }
};