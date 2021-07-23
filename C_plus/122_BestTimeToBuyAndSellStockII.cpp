class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // option 1 use dp

        //      7   1   5   3   6   4
        //      sell(0) hold(1)
        //  dp[i][0] = max( dp[i-1][0], dp[i-1][1] + prices[i]);
        //  dp[i][1] = max( dp[i-1][1], dp[i-1][0] - prices[i]);
        //7     0     -7
        //1     0     0
        //5     0     0
        //3     0     0
        //6     0     0   
        //4     0     0
        
        //         int n = prices.size();
        //         vector<vector<int>> dp(n ,vector<int>(2,0));
        //         dp[0][0] = 0;
        //         dp[0][1] = -prices[0];
        //         for(int i=1;i<n;++i){

        //             dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        //             dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);

        //         }
        //         return dp[n-1][0];

        // option 1.2 簡化dp
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for (int i = 1; i < n; ++i)
        {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;

        // option 2
        // int ret = 0;
        // int n = prices.size();
        // for(int i=1;i<n;++i){
        //     int profit = prices[i]-prices[i-1];
        //     ret += profit>0?profit:0;
        // }
        // return ret;
    }
};