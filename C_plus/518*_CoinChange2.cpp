class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        // 完全背包問題
        // 322. Coin Change
        //
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= amount; j++) {
        //         if (j - coins[i-1] >= 0)
        //             dp[i][j] = dp[i - 1][j]  + dp[i][j-coins[i-1]];
        // return dp[N][W]

        //      1 2 5
        //  0   1   2   3   4   5
        //  1   0   0   0   0   0   , initialize
        //  1   1   1   1   1   1   , i = 1 , coins[i-1] = 1
        //  1   1   2   2   3   3   , i = 2 coins[i-1] = 2
        //  1   1   2   2   3   4   , i = 3 coins[i-1]  = 5

        int n = coins.size();
        vector<vector<int> > dp(n + 1, vector<int>(amount + 1, 0));
        // base case
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {
                if (j - coins[i - 1] >= 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][amount];

        // option 2 壓縮dp
        // vector<int> dp(amount+1, amount+1);
        //         dp[0] = 0;
        //         for(int i= 1;i<=amount ;++i){
        //             for(int coin :coins){
        //                 if(i-coin<0) continue;
        //                 dp[i] = min(dp[i], 1+dp[i-coin]);
        //             }
        //         }

        //  if (i - coin >= 0)    dp[i] = dp[i] + dp[i-coin];
        //   1 2 5
        //  0   1   2   3   4   5
        //  1   0   0   0   0   0
        //
        //  1   1   1   1   1   1   , i =0 , coins[i] = 1
        //  1   1   2   2   3   3   ,  i = 1, coins[i] = 2
        //  1   1   2   2   3   4   ,  i =2 , coins[i] = 5
        //

        //         vector<int> dp(amount+1, 0);
        //         dp[0] = 1;
        //         for(int i=0;i<coins.size();++i){
        //             for(int j = 1;j<=amount ; ++j){
        //                 if( j - coins[i] >=0) dp[j] = dp[j] + dp[j-coins[i]];
        //             }
        //         }

        //         return dp[amount]==amount+1?1:dp[amount];
    }
};