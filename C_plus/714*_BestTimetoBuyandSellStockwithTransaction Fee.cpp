class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee)
        // 解释：相当于买入股票的价格升高了。
        // 在第一个式子里减也是一样的，相当于卖出股票的价格减小了。
        // int n = prices.size();
        // vector<vector<int>> dp(n ,vector<int>(2,0));
        // dp[0][0] = 0;
        // dp[0][1] = -prices[0]-fee;
        // for(int i=1;i<n;++i){
        //     dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        //     dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee);
        // }
        // return dp[n-1][0];

        // option 1.2 improved dp
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = -prices[0] - fee;
        for (int i = 1; i < n; ++i)
        {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, dp_i_0 - prices[i] - fee);
        }
        return dp_i_0;
    }
};