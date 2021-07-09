class Solution
{
public:
    int maxProductPath(vector<vector<int> > &grid)
    {

        // option 1 maintain two dp to dividually store max and min value until now;
        int n = grid.size(), m = grid[0].size();
        vector<vector<long> > maxCache(n, vector<long>(m, 0));
        vector<vector<long> > minCache(n, vector<long>(m, 0));

        long long mod = 1e9 + 7;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {

                long maxVal = INT_MIN, minVal = INT_MAX;
                if (i == 0 && j == 0)
                {
                    maxVal = grid[i][j];
                    minVal = grid[i][j];
                }

                else if (i == 0)
                {
                    long tempMax = max(grid[i][j] * minCache[i][j - 1], grid[i][j] * maxCache[i][j - 1]);
                    maxVal = max(maxVal, tempMax);

                    long tempMin = min(grid[i][j] * minCache[i][j - 1], grid[i][j] * maxCache[i][j - 1]);
                    minVal = min(minVal, tempMin);
                }
                else if (j == 0)
                {
                    long tempMax = max(grid[i][j] * minCache[i - 1][j], grid[i][j] * maxCache[i - 1][j]);
                    maxVal = max(maxVal, tempMax);

                    long tempMin = min(grid[i][j] * minCache[i - 1][j], grid[i][j] * maxCache[i - 1][j]);
                    minVal = min(minVal, tempMin);
                }
                else
                {
                    long tempMax = max(grid[i][j] * minCache[i - 1][j], grid[i][j] * minCache[i][j - 1]);
                    maxVal = max(maxVal, tempMax);
                    tempMax = max(grid[i][j] * maxCache[i - 1][j], grid[i][j] * maxCache[i][j - 1]);
                    maxVal = max(maxVal, tempMax);

                    long tempMin = min(grid[i][j] * minCache[i - 1][j], grid[i][j] * minCache[i][j - 1]);
                    minVal = min(minVal, tempMin);
                    tempMin = min(grid[i][j] * maxCache[i - 1][j], grid[i][j] * maxCache[i][j - 1]);
                    minVal = min(minVal, tempMin);
                }
                maxCache[i][j] = maxVal;
                minCache[i][j] = minVal;
            }
        }
        return maxCache[n - 1][m - 1] < 0 ? -1 : maxCache[n - 1][m - 1] % mod;
    }
};