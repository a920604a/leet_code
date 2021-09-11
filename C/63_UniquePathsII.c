

int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize)
{
    int **dp;
    dp = calloc(obstacleGridSize, sizeof(int *));
    for (int i = 0; i < obstacleGridSize; ++i)
    {
        dp[i] = calloc(*obstacleGridColSize, sizeof(int));
    }
    // for(int i=0;i<obstacleGridSize;++i){
    //     for(int j=0;j<*obstacleGridColSize ;++j){
    //         printf("%d\t", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    //  0   0   0       1   1   1
    //  0   1   0       1   0   1
    //  0   0   0       1   1   2

    for (int i = 0; i < obstacleGridSize; ++i)
    {
        for (int j = 0; j < *obstacleGridColSize; ++j)
        {
            if (obstacleGrid[i][j] == 1)
                continue;
            else if (obstacleGrid[i][j] == 0)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1];
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    // for(int i=0;i<obstacleGridSize;++i){
    //     for(int j=0;j<*obstacleGridColSize ;++j){
    //         printf("%d\t", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    int ret = dp[obstacleGridSize - 1][*obstacleGridColSize - 1];
    for (int i = 0; i < obstacleGridSize; ++i)
        free(dp[i]);

    return ret;
}