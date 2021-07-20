class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 原始的动态转移方程，没有可化简的地方
        // dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
        // dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])

        //         int n = prices.size(), k=2;
        //         vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2,0)));
        //         dp[0][2][0] = 0;
        //         dp[0][1][0] = 0;
        //         dp[0][2][1] = -prices[0];
        //         dp[0][1][1] = -prices[0];

        //         for(int i=1;i<n;++i){
        //             // dp[i][k][0] = max( dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
        //             // dp[i][k][1] = max( dp[i-1][k][1], dp[i-1][k][0] - prices[i]);
        //             dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i]);
        //             dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i]);
        //             dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i]);
        //             dp[i][1][1] = max(dp[i-1][1][1], -prices[i]);

        //         }
        //         return dp[n-1][k][0];

        int dp_i10 = 0, dp_i11 = INT_MIN;
        int dp_i20 = 0, dp_i21 = INT_MIN;
        for (int price : prices)
        {
            dp_i20 = max(dp_i20, dp_i21 + price);
            dp_i21 = max(dp_i21, dp_i10 - price);
            dp_i10 = max(dp_i10, dp_i11 + price);
            dp_i11 = max(dp_i11, -price);
        }
        return dp_i20;
    }
};