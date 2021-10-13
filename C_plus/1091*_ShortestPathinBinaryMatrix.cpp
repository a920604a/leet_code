class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int> > &grid)
    {

        // BFS

        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
            return -1;
        vector<vector<int> > acts = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        queue<vector<int> > q;
        q.push({0, 0});
        int len = 1;
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        visited[0][0] = true;
        // directly change the visited cell to grid[i][j] = 1 to avoid repeatedly visiting. No need for boolean arr.

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                vector<int> p = q.front();
                if (p[0] == n - 1 && p[1] == m - 1)
                    return len;
                q.pop();
                for (vector<int> a : acts)
                {
                    int x = p[0] + a[0];
                    int y = p[1] + a[1];
                    if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || grid[x][y] == 1 || visited[x][y])
                        continue;
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
            len++;
        }
        return -1;
    }
};