class Solution
{
public:
    int orangesRotting(vector<vector<int> > &grid)
    {

        // BFS
        // find 2 index
        int n = grid.size(), m = grid[0].size(), freshLeft = 0;
        queue<vector<int> > q;
        // if(n==1 && m==1) return grid[0][0]!=1?0:-1;
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < m; ++y)
            {
                if (grid[x][y] == 1)
                    freshLeft++;
                else if (grid[x][y] == 2)
                {
                    q.push({x, y});
                }
            }
        }
        vector<vector<int> > act = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int ret = 0;
        while (!q.empty() && freshLeft > 0)
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                vector<int> cur = q.front();
                q.pop();
                for (vector<int> a : act)
                {
                    int x = cur[0] + a[0], y = cur[1] + a[1];
                    if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || grid[x][y] == 0 || grid[x][y] == 2)
                        continue;
                    grid[x][y] = 2;
                    q.push({x, y});
                    freshLeft--;
                }
            }
            ret++;
        }
        return freshLeft > 0 ? -1 : ret;
    }
};