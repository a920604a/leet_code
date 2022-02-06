#define min(a, b) ((a < b) ? a : b)

int coinChange(int *coins, int coinsSize, int amount)
{

    //  0   1   2   3   4   5   6   7   8   9   10  11
    //  0   1   2   3   4   5   6   7   8   9   10  11
    //  0   1   1   2   2   3   3   4   4   5   5   6
    //  0   1   1   2   2   1   2   2   3   3   2   3

    int *dp = calloc(amount + 1, sizeof(int));
    for (int i = 1; i < amount + 1; ++i)
        dp[i] = amount + 1;
    for (int i = 0; i < coinsSize; ++i)
    {
        for (int j = 1; j < amount + 1; ++j)
        {
            if (j >= coins[i])
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
            // printf("%d ", dp[j]);
        }
        // printf("\r");
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}