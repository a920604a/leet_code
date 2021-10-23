class Solution
{
public:
    void dfs(vector<vector<int> > &grid, int i, int j)
    {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i > n - 1 || j > m - 1 || grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
    }
    int countSubIslands(vector<vector<int> > &grid1, vector<vector<int> > &grid2)
    {

        // 子島 ，假設 grid2 中島嶼的每一個cell都被grid1 的同一個島嶼完全包含，則視為子島
        // grid2 是陸地，但grid1 是海，那就淹掉，
        int cnt = 0;
        int n = grid1.size(), m = grid1[0].size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid1[i][j] == 0 && grid2[i][j] == 1)
                    dfs(grid2, i, j);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid2[i][j] == 0)
                    continue;
                cnt++;
                dfs(grid2, i, j);
            }
        }
        return cnt;
    }
};