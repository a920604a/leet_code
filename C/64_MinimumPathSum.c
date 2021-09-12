
#define min(a, b) ((a < b) ? a : b)
int minPathSum(int **grid, int gridSize, int *gridColSize)
{

    //  1   3   1       1   4   5
    //  1   5   1       2   7   6
    //  4   2   1       6   8   7

    int **dp = malloc(gridSize * sizeof(int *));
    for (int i = 0; i < gridSize; ++i)
        dp[i] = malloc(*(gridColSize + i) * sizeof(int));

    for (int i = 0; i < gridSize; ++i)
    {
        for (int j = 0; j < *(gridColSize + i); ++j)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else if (i == 0)
                dp[i][j] = grid[i][j] + dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = grid[i][j] + dp[i - 1][j];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    int ret = dp[gridSize - 1][*(gridColSize + gridSize - 1) - 1];
    for (int i = 0; i < gridSize; ++i)
        free(dp[i]);
    return ret;
}