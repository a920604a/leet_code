class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // option 1 use dp
        // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        // dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
        // 解释：第 i 天选择 buy 的时候，要从 i-2 的状态转移，而不是 i-1 。
        // 每次 sell 之后要等一天才能继续交易buy買
        //         int n = prices.size();
        //         if(n==1) return 0;
        //         vector<vector<int>> dp(n ,vector<int>(2,0));
        //         dp[1][0] = max(dp[0][0], dp[0][1]+ prices[1]);
        //         dp[1][1] = max(dp[0][1], -prices[1]);
        //         for(int i=2;i<n;++i){
        //             // 未持有股票
        //             dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        //             // 持有股票
        //             dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        //             // 每次 sell 之后要等一天才能继续交易
        //             cout<<dp[i][0]<<" "<<dp[i][1]<<endl;

        //         }
        //         return dp[n-1][0];

        // optnio 1.1 簡化dp
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        int dp_pre_0 = 0; // 代表 dp[i-2][0]
        for (int i = 0; i < n; ++i)
        {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
            dp_pre_0 = temp;
        }
        return dp_i_0;
    }
};