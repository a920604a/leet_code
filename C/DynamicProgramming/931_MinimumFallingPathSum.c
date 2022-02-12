#define min(a, b) ((a < b) ? a : b)

int minFallingPathSum(int **matrix, int matrixSize, int *matrixColSize)
{
    int **dp = calloc(matrixSize, sizeof(int *));
    for (int i = 0; i < matrixSize; ++i)
        dp[i] = calloc(matrixSize, sizeof(int));
    int ret = INT_MAX;
    for (int i = 0; i < *matrixColSize; ++i)
    {
        dp[0][i] = matrix[0][i];
        ret = min(ret, dp[0][i]);
    }
    if (matrixSize == 1)
        return ret;
    ret = INT_MAX;
    for (int i = 1; i < matrixSize; ++i)
    {
        for (int j = 0; j < matrixColSize[i]; ++j)
        {
            dp[i][j] = matrix[i][j];
            if (j == 0)
                dp[i][j] += min(dp[i - 1][j], dp[i - 1][j + 1]);
            else if (j == matrixSize - 1)
                dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j]);
            else
                dp[i][j] += min(min(dp[i - 1][j - 1], dp[i - 1][j + 1]), dp[i - 1][j]);
            // printf("%d ", dp[i][j]);
            if (i == matrixSize - 1)
                ret = min(ret, dp[i][j]);
        }
        // printf("\r");
    }
    return ret;
}