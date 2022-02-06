#define min(a, b) ((a < b) ? a : b)

int mincostTickets(int *days, int daysSize, int *costs, int costsSize)
{

    //      1   4   6   7   8   20
    //  0   2   4   6   8   10  12
    //  0   2   4   6   7

    //  1   2   3  4   5   6   7   8   9  10  30  31
    //

    int *dp = calloc(daysSize + 1, sizeof(int));

    for (int i = 1; i < daysSize + 1; ++i)
    {
        dp[i] = dp[i - 1] + costs[0];
        for (int j = 1; j <= i; ++j)
        {
            if (days[i - 1] - days[j - 1] < 7)
                dp[i] = min(dp[i], dp[j - 1] + costs[1]);
            if (days[i - 1] - days[j - 1] < 30)
                dp[i] = min(dp[i], dp[j - 1] + costs[2]);
        }
    }
    return dp[daysSize];
}