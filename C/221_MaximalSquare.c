#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int maximalSquare(char **matrix, int matrixSize, int *matrixColSize)
{

    //  1   0   1   0   0       1   0   1   0   0
    //  1   0   1   1   1       1   0   1   1   1
    //  1   1   1   1   1       1   1   1   2   2
    //  1   0   0   1   0       1   0   0   1   0

    int **dp = malloc(matrixSize * sizeof(int *));
    for (int i = 0; i < matrixSize; ++i)
        dp[i] = malloc(*(matrixColSize + i) * sizeof(int));
    int ret = 0;
    for (int i = 0; i < matrixSize; ++i)
    {
        for (int j = 0; j < *(matrixColSize + i); ++j)
        {
            if (matrix[i][j] == '0')
                dp[i][j] = 0;
            else
            {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j] - '0';
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            ret = max(ret, dp[i][j]);
        }
    }

    for (int i = 0; i < matrixSize; ++i)
        free(dp[i]);
    return ret * ret;
}