

int numTrees(int n)
{
    int *dp = calloc(n + 1, sizeof(int));
    // n=1, 1
    // n=2, 2
    // n =3, 5 = 1*2 + 2*1
    //n=4 , 14 = 5*2
    // n =5 , 42
    // dp
    // 1, 1, dp[0]*dp[1]+dp[1]*dp[0], dp[0]*dp[2]+dp[1]*dp[1]+dp[2]*dp[0]
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    return dp[n];
}