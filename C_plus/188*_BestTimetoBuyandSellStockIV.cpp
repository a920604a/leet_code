class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for (int i = 1; i < n; ++i)
        {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int n = prices.size();
        if (k > n / 2)
            return maxProfit(prices);

        vector<vector<vector<int> > > dp(n, vector<vector<int> >(k + 1, vector<int>(2, 0)));
        for (int i = 0; i < n; ++i)
        {
            for (int kk = k; kk >= 1; kk--)
            {
                if (i == 0)
                {
                    dp[i][kk][0] = 0;
                    dp[i][kk][1] = -prices[i];
                    continue;
                }
                dp[i][kk][0] = max(dp[i - 1][kk][0], dp[i - 1][kk][1] + prices[i]);
                dp[i][kk][1] = max(dp[i - 1][kk][1], dp[i - 1][kk - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][k][0];
    }
};