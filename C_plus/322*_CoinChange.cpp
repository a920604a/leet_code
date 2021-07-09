class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        vector<int> dp(amount + 1, amount + 1);  // 籌到amount最短可以使用多少個硬幣
        dp[0] = 0;
        for (int i = 0; i <= amount; ++i)
        {
            for (int coin : coins)
            {

                if (i >= coin)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return dp[amount]==amount+1 ? -1 : dp[amount];
    }
};
