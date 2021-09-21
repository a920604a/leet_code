class Solution
{
public:
    int orangesRotting(vector<vector<int> > &grid)
    {
        queue<vector<int> > q;
        int n = grid.size(), m = grid[0].size();
        int freshLeft = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                    freshLeft++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        // (0,-1) (-1,0) (0,1) (1,0)
        vector<int> acts = {0, -1, 0, 1};
        int step = 0;
        while (!q.empty() && freshLeft > 0)
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                auto p = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j)
                {
                    int x = p[0] + acts[j % 4], y = p[1] + acts[(j + 1) % 4];
                    if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 2;
                    q.push({x, y});
                    freshLeft -= 1;
                }
            }
            step += 1;
        }
        if (freshLeft > 0)
            return -1;

        return step;
    }
};