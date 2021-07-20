class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // option 1 use dp
        // 7  1 5 3 6 4
        // 0  0 4 4 5 5
        // -7 -1 -1 -1 -1 -1
        // https://labuladong.gitbook.io/algo/mu-lu-ye/tuan-mie-gu-piao-wen-ti
        //         int n = prices.size();
        //         vector<vector<int>> dp(n ,vector<int>(2,0));
        //         for(int i=0;i<n;++i){
        //             if(i-1==-1){
        //                 dp[i][0] = 0;
        //                 dp[i][1] = -prices[i];
        //                 continue;
        //             }
        //             // 0 沒持有股票，本身就沒持有，或是昨天有持有但賣掉
        //             dp[i][0] = max( dp[i-1][0], dp[i-1][1] + prices[i]);
        //             // 1 持有股票，本身就持有股票，或是昨天還沒有股票今天買
        //             dp[i][1] = max(dp[i-1][1], -prices[i]);

        //         }
        //         return dp[n-1][0]; // 0 沒持有股票，因為最後一定要賣掉

        // option 1.2 簡化dp
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = -prices[0];
        for (int i = 0; i < n; ++i)
        {
            // dp[i][0] = max( dp[i-1][0], dp[i-1][1] + prices[i]);
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            // dp[i][1] = max(dp[i-1][1], -prices[i]);
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;

        // option 2
        // int _min = INT_MAX;
        // int ret= 0;
        // int n = prices.size();
        // for(int i=0;i<n;++i){
        //     ret = max(ret, prices[i] - _min);
        //     _min = min(_min, prices[i]);
        // }
        // return ret;
    }
};