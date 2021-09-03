class Solution
{
public:
    void traverse(vector<vector<int> > &grid, int i, int j, vector<vector<bool> > &visited, int &area)
    {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || i > n - 1 || j < 0 || j > m - 1 || visited[i][j] || grid[i][j] == 0)
            return;
        visited[i][j] = true;
        area++;
        traverse(grid, i - 1, j, visited, area);
        traverse(grid, i, j - 1, visited, area);
        traverse(grid, i + 1, j, visited, area);
        traverse(grid, i, j + 1, visited, area);
    }
    int maxAreaOfIsland(vector<vector<int> > &grid)
    {
        // option 1 DFS
        int ret = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 0 || visited[i][j])
                    continue;
                int area = 0;
                traverse(grid, i, j, visited, area);
                ret = max(ret, area);
            }
        }
        return ret;
        // option 2 BFS  + queue
    }
};