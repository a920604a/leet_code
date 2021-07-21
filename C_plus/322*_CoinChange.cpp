class Solution
{
public:
    // dp(n) =  0 , n=0
    // dp(n) = -1,  n<-1
    // dp(n) = min{dp(n-coin) + 1 | for all coin in coins}, n>0
    int dp(int n, vector<int> &coins)
    {
        // base case
        if (n == 0)
            return 0;
        if (n < 0)
            return -1;

        int ret = INT_MAX;
        for (int coin : coins)
        {
            int subproblem = dp(n - coin, coins);
            // # 子問題無解，跳過
            if (subproblem == -1)
                continue;
            ret = min(ret, 1 + subproblem);
        }

        return ret != INT_MAX ? ret : -1;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        // option 1 brute force => time out
        // return dp(amount, coins);

        // option memo pattern 消除一下重叠子问题
        // O(kn) time
        // map<int,int> memo;
        // return dp(amount, coins, memo);

        //option 2 dp
        //  1 2 5
        //   0  1    2   3   4   5   6   7   8   9  10  11    = i
        //   0  12  12  12  12  12  12  12  12  12  12  12
        //
        //   0   1   1   2   3   1   2   2   3   3   2   3

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {

            for (int coin : coins)
            {
                if (i - coin < 0)
                    continue;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }

    int dp(int n, vector<int> &coins, map<int, int> &memo)
    {
        if (memo.count(n))
            return memo[n];

        // base case
        if (n == 0)
            return 0;
        if (n < 0)
            return -1;

        int ret = INT_MAX;
        for (int coin : coins)
        {
            int subproblem = dp(n - coin, coins, memo); // O(k)
            // # 子問題無解，跳過
            if (subproblem == -1)
                continue;
            ret = min(ret, 1 + subproblem);
        }
        memo[n] = ret != INT_MAX ? ret : -1;
        return memo[n];
    }
};