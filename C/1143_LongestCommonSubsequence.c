#define max(a, b) ((a > b) ? a : b)

int longestCommonSubsequence(char *text1, char *text2)
{

    //      a   c   e
    //      0   0   0
    //a  0  1   1   1
    //b  0  1   1   1
    //c     1   2   2
    //d     1   2   2
    //e     1   2   3

    int n = strlen(text1), m = strlen(text2);
    int **dp = calloc(n + 1, sizeof(int *));
    for (int i = 0; i <= n; ++i)
        dp[i] = calloc(m + 1, sizeof(int));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}