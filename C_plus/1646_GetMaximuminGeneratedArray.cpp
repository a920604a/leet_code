class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        // option 1 dp
        vector<int> dp(n + 1, 0);
        int ret = 0;
        int k = 0;
        if (n < 2)
            return n;
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
                dp[i] = dp[i / 2];
            else
                dp[i] = dp[i / 2] + dp[i / 2 + 1];
            ret = max(dp[i], ret);
        }
        return ret;
    }
};