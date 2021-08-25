class Solution
{
public:
    int islandPerimeter(vector<vector<int> > &grid)
    {

        // 因為是相連所以每個方塊 最多貢獻3 個周長，
        // 再去判斷這些方塊 相鄰塊總數
        int m = grid.size(), n = grid[0].size();
        int ret = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {

                if (grid[i][j] == 1)
                {
                    int count = 4;
                    if (j > 0 && grid[i][j - 1] == 1)
                        count--;
                    if (i > 0 && grid[i - 1][j] == 1)
                        count--;

                    if (i < m - 1 && grid[i + 1][j] == 1)
                        count--;
                    if (j < n - 1 && grid[i][j + 1] == 1)
                        count--;

                    ret += count;
                }
            }
        }

        return ret;
    }
};