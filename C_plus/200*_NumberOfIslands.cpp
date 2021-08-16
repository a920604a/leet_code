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