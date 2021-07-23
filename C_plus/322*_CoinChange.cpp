class Solution
{
public:
    int change(vector<int> &coins, int amount)
    {
        // base case
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        int ret = INT_MAX;
        for (int coin : coins)
        {
            int subproblem = change(coins, amount - coin);
            if (subproblem == -1)
                continue;
            ret = min(ret, 1 + subproblem);
        }
        return ret == INT_MAX ? -1 : ret;
    }
    int change(vector<int> &coins, int amount, unordered_map<int, int> &memo)
    {
        // 查看備忘錄是否已存在
        if (memo.count(amount))
            return memo[amount];

        // base case
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        int ret = INT_MAX;

        for (int coin : coins)
        {
            int subproblem = change(coins, amount - coin, memo);
            if (subproblem == -1)
                continue;
            ret = min(ret, 1 + subproblem);
        }
        // 放進備忘錄
        memo[amount] = ret == INT_MAX ? -1 : ret;
        return memo[amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {

        // option 1 brute force recursive
        // Time Limit Exceeded

        // 想求amount = 11 時最少硬幣數，必須先知道amount = 10時最少硬幣數，以此類推。
        // return change(coins, amount);

        // option 2 memo pattern
        unordered_map<int, int> memo;
        return change(coins, amount, memo);

        // option 3 dp
        //
        //      0   1   2   3   4   5   6   7   8   9   10  11
        //      11  11  11  11  11  11  11  11  11  11  11  11
        //  1   0   1   2   3   4   5   6   7   8   9   10  11
        //  2   0   1   1
        //  5   0
        //  if(j>= coins[i] ) dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]] + 1);
        //  else dp[i][j] = dp[i-1][j];
        // int n = coins.size();
        // vector<vector<int>> dp(n+1, vector<int>(amount+1,amount+1));
        // for(int i=0;i<=n ; ++i)  dp[i][0] = 0; //initialize
        // for(int i=1;i<=n ;++i){
        //     for(int j=1;j<=amount ;++j){
        //         if(j >= coins[i-1]) dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
        //         else dp[i][j] = dp[i-1][j];
        //     }
        // }
        // return dp[n][amount] == amount+1?-1:dp[n][amount];

        // option 4 壓縮 dp

        // int n = coins.size();
        // vector<int> dp(amount+1,amount+1);
        // dp[0] = 0; //initialize
        // for(int i=0;i<n ;++i){
        //     for(int j=1;j<=amount ;++j){
        //         if( j >= coins[i]) dp[j] = min(dp[j], dp[j-coins[i]] +1 );
        //     }
        // }
        // return dp[amount] == amount+1?-1:dp[amount];
    }
};